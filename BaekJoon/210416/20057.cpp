#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int N, cur_i, cur_j, cur_d;
int ans = 0;
vector <vector<int>> map;
int di[4] = {0, 1, 0, -1};
int dj[4] = {-1, 0, 1, 0};

float di0[10][3] = {
    {-1, 0, 0.01},
    {1, 0, 0.01},
    {-2,-1, 0.02},
    {2, -1, 0.02},
    {-1,-1,0.07},
    {1,-1,0.07},
    {-1,-2,0.1},
    {1,-2,0.1},
    {0,-3,0.05},
    {0,-2,0}
};


float di1[10][3] = {
    {0, -1, 0.01},
    {0, 1, 0.01},
    {1,-2, 0.02},
    {1, 2, 0.02},
    {1,-1,0.07},
    {1,1,0.07},
    {2,-1,0.1},
    {2,1,0.1},
    {3,0,0.05},
    {2,0,0}
};

float di2[10][3] = {
    {-1, 0, 0.01},
    {1, 0, 0.01},
    {-2,1, 0.02},
    {2, 1, 0.02},
    {-1,1,0.07},
    {1,1,0.07},
    {-1,2,0.1},
    {1,2,0.1},
    {0,3,0.05},
    {0,2,0}
};

float di3[10][3] = {
    {0,-1, 0.01},
    {0,1, 0.01},
    {-1,-2, 0.02},
    {-1,2, 0.02},
    {-1,-1,0.07},
    {-1,1,0.07},
    {-2,-1,0.1},
    {-2,1,0.1},
    {-3,0,0.05},
    {-2,0,0}
};


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    map.assign(N, vector<int>(N));

    for(int n=0; n<N; n++){
        for(int m=0; m<N; m++){
            cin >> map[n][m];
        }
    }
    cur_i = N/2;
    cur_j = N/2;
    cur_d = 0;
    for(int n=1; n<N; n++){

        for(int m=0; m<2; m++){
            

            float di_temp[10][3];
            if(cur_d == 0){
                memcpy(di_temp, di0, sizeof(di0));
            }else if(cur_d == 1){
                memcpy(di_temp, di1, sizeof(di1));
            }else if(cur_d == 2){
                memcpy(di_temp, di2, sizeof(di2));
            }else if(cur_d == 3){
                memcpy(di_temp, di3, sizeof(di3));
            }


            for(int h=0; h<n; h++){
                int nxt_i = cur_i+di[cur_d];
                int nxt_j = cur_j+dj[cur_d];
            
                int morae = map[nxt_i][nxt_j];

                map[nxt_i][nxt_j] = 0;
                int temp=0;
                for(int a=0; a<9; a++){
                    int temp_i = cur_i + di_temp[a][0];
                    int temp_j = cur_j + di_temp[a][1];

                    if(temp_i <0 || temp_i >= N || temp_j<0|| temp_j>=N){
                        ans += int(morae*di_temp[a][2]);
                        temp +=int(morae*di_temp[a][2]);
                        
                    }else{
                        map[temp_i][temp_j] += int(morae*di_temp[a][2]);
                        temp +=int(morae*di_temp[a][2]);
                        
                    }
                }

                int temp_i = cur_i + di_temp[9][0];
                int temp_j = cur_j + di_temp[9][1];

                if(temp_i <0 || temp_i >= N || temp_j<0|| temp_j>=N){
                    ans += (morae-temp);
                }else{
                    map[temp_i][temp_j] += (morae-temp);
                }

                cur_i = nxt_i;
                cur_j = nxt_j;


            }

            if(cur_d == 3){
                cur_d = 0;
            }else cur_d++;


            if(cur_i == 0 && cur_j==N-1){
                m--;
            }
        }
    }
    
    
    cout << ans;

}