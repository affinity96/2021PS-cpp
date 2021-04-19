#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
int N, Q;
int POW;
int max_dong = 0;
vector <vector <int>> map;
int di[4] = {-1,0,1,0};
int dj[4] = {0,-1,0,1};

void play(int magic){
    int magic_num = pow(2,magic);
    if(magic != 0){
        
        for(int i=0; i<POW; i+=magic_num){
            for(int j=0; j<POW; j+=magic_num){
                vector<vector<int>>temp(magic_num, vector<int>(magic_num));

                for(int a=0; a<magic_num; a++){
                    for(int b=0; b<magic_num; b++){
                        temp[a][b] = map[i+(magic_num - 1 -b)][j+a];
                    }
                }

                for(int a=0; a<magic_num; a++){
                    for(int b=0; b<magic_num; b++){
                        map[i+a][j+b] = temp[a][b];
                    }
                }
            }
        }
    }
    

    vector<vector<int>>temp_map(POW, vector<int>(POW));
    for(int i=0; i<POW; i++){
        for(int j=0; j<POW; j++){
            int cnt=0;
            for(int d=0; d<4; d++){
                int nxt_i = i+di[d];
                int nxt_j = j+dj[d];

                if(nxt_i < 0 || nxt_i >= POW || nxt_j<0 || nxt_j>=POW) continue;
                if(map[nxt_i][nxt_j] >= 1){
                    cnt++;
                }
            }

            if(cnt <3){
                temp_map[i][j] = map[i][j]-1;
            }else{
                temp_map[i][j] = map[i][j];
            }
        }
    }

    copy(temp_map.begin(), temp_map.end(), map.begin());


}


void bfs(int i, int j){
    vector<vector<bool>>visited(POW, vector<bool>(POW));
    queue <pair<int, int>> q;
    int cnt = 0;
    q.push(make_pair(i,j));
    visited[i][j] = true;
    while(!q.empty()){
        int cur_i = q.front().first;
        int cur_j = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int nxt_i = cur_i + di[d];
            int nxt_j = cur_j + dj[d];

            if(nxt_i < 0 || nxt_i >= POW || nxt_j<0 || nxt_j>=POW) continue;
            if(map[nxt_i][nxt_j] <=0 || visited[nxt_i][nxt_j]) continue;

            q.push(make_pair(nxt_i, nxt_j));
            visited[nxt_i][nxt_j] = true;
            cnt++;
        }
    }

    if(cnt > max_dong){
        max_dong = ++cnt;
    }
}

int main(){

    cin >> N >> Q;
    
    POW = pow(2, N);
    map.assign(POW, vector<int>(POW));
    
    for(int n=0; n<POW; n++){
        for(int m=0; m<POW; m++){
            cin >> map[n][m];
        }
    }
    vector<int>q_list(Q);
    for(int q=0; q<Q; q++){
        cin >> q_list[q];
    }
    for(int q=0; q<Q; q++){
        play(q_list[q]);
    }
    int ans = 0;
    for(int i=0; i<POW; i++){
        for(int j=0; j<POW; j++){
            if(map[i][j] > 0){
                ans += map[i][j];
                bfs(i,j);
            }
        }
    }

    cout << ans << "\n" << max_dong;
}