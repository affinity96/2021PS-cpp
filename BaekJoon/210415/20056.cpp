#include <iostream>
#include <vector>

using namespace std;
int N, M, K;

int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Fire{
    int i;
    int j;
    int m;
    int d;
    int s;
    int k;

};

vector<vector<vector<Fire>>> map;

int main(){
    cin >> N >> M >> K;
    map.assign(N,vector<vector<Fire>>(N));
    
    for(int m=0; m<M; m++){
        Fire fire;
        int temp_i, temp_j;

        cin >> temp_i >> temp_j >> fire.m >> fire.s >> fire.d;
        fire.i = temp_i-1;
        fire.j = temp_j-1;
        fire.k = 0;

        map[fire.i][fire.j].push_back(fire);
    }

    for(int k=1; k<=K; k++){
        for(int n=0; n<N; n++){
            for(int m=0; m<N; m++){
                
                if(!map[n][m].empty()){
                    int size = map[n][m].size();
                    for(int s=0; s<size; s++){
                        if(map[n][m][s].m!=0 && map[n][m][s].k == k-1){
                            
                            int nxt_i = (map[n][m][s].i + di[map[n][m][s].d] * map[n][m][s].s);
                            int nxt_j = (map[n][m][s].j + dj[map[n][m][s].d] * map[n][m][s].s);
                            if(nxt_i < 0){
                                while(nxt_i < 0){
                                    nxt_i += N;
                                }
                            }
                            if(nxt_j < 0){
                                while(nxt_j < 0){
                                    nxt_j += N;
                                }
                            }
                            nxt_i = nxt_i%N;
                            nxt_j = nxt_j%N;

                            //cout << nxt_i << nxt_j;
                            Fire fire = map[n][m][s];
                            fire.i = nxt_i;
                            fire.j = nxt_j;
                            fire.k = k;
                            map[nxt_i][nxt_j].push_back(fire);
                        }
                        

                    }
                }
            }
        }

        for(int n=0; n<N; n++){
            for(int m=0; m<N; m++){
                if(!map[n][m].empty()){
                    int size_ = map[n][m].size();
                   // cout <<"!"<< size_ << "!";
                    vector<int>temp_v;
                    for(int s=0; s<map[n][m].size(); s++){
                        if(map[n][m][s].k != k){  
      
                            map[n][m].erase(map[n][m].begin() + s);
                            s--;
                        }
                    }

                    size_ = map[n][m].size();

                    if(size_>=2){
                        int sum_m = 0;
                        int sum_s = 0;
                        int temp = (map[n][m][0].d)%2;
                        int isEqual = 1;
                        for(int s=0; s<size_; s++){
                            sum_m += map[n][m][s].m;
                            sum_s += map[n][m][s].s;
                            if(map[n][m][s].d %2 != temp){
                                isEqual = 0;
                            }
                        }
                        int cur_m = sum_m/5;
                        int cur_s = sum_s/size_;

                        if(cur_m == 0) {
                            map[n][m] = {};
                        }else{
                            if(isEqual){
                                map[n][m] = {};
                                for(int i=0; i<4; i++){
                                    Fire fire;
                                    fire.d = 2*i;
                                    fire.i = n;
                                    fire.j = m;
                                    fire.k = k;
                                    fire.m = cur_m;
                                    fire.s = cur_s;
                                    map[n][m].push_back(fire);
                                }
                            }else{
                                map[n][m] = {};
                                for(int i=0; i<4; i++){
                                    Fire fire;
                                    fire.d = 2*i+1;
                                    fire.i = n;
                                    fire.j = m;
                                    fire.k = k;
                                    fire.m = cur_m;
                                    fire.s = cur_s;
                                    map[n][m].push_back(fire);
                                }
                            }
                            


                        }

                        
                    }


                }
            }

            

        }


    }

    int ans =0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!map[i][j].empty()){
                for(int s=0; s<map[i][j].size(); s++){
                    ans += map[i][j][s].m;
                }
            }
        }
    }

    cout<<ans;


}