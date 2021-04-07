#include <iostream>
#include <vector>

using namespace std;
int N, M, ci, cj, cd;
int ans = 0;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

vector<vector<int>>room;
int turn_left(int cur){
    if (cur == 0) return 3;
    if (cur == 1) return 0;
    if (cur == 2) return 1;
    if (cur == 3) return 2;
}
void dfs(int i, int j, int d){

    int flag = 1;
    int cnt = 0;

    while(flag){
        
        if(cnt == 4){
            int ni = i-di[cd];
            int nj = j-dj[cd];
            
            if(room[ni][nj]==1){
                
                flag = 0;
                break;
            }else{
                cnt = 0;
                i = ni;
                j = nj;
                continue;
            }
        }

        if(room[i][j]==0){
            ans ++;
            room[i][j] = 2;
        }
        //방향바꿔봐 왼쪽으로
        cd = turn_left(cd);

        int ni = i+di[cd];
        int nj = j+dj[cd];

        if(room[ni][nj] == 0){
            i = ni; j=nj;
            cnt = 0;
            continue;
        }else{
            cnt ++;
            continue;
        }

        


        
    }
    
    
    

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    room.assign(N, vector<int>(M));

    cin >> ci >> cj >> cd;

    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            cin >> room[n][m];
        }
    }

    dfs(ci, cj, cd);

    cout << ans;
}