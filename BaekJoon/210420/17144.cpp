#include <iostream>
#include <vector>
using namespace std;
int R, C, T;
int m1_i, m2_i;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};

int form1i[4] = {-1, 0, 1, 0};
int form1j[4] = {0, 1, 0, -1};

int form2i[4] = {1, 0, -1, 0};
int form2j[4] = {0, 1, 0, -1};

vector <vector<int>> map;
int main(){
    cin >> R >> C >> T;
    map.assign(R, vector<int>(C));
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){

            cin >> map[r][c];
            if(map[r][c]==-1){
                m2_i = r;
            }
        }
    }

    m1_i = m2_i-1;

    for(int t=0; t<T; t++){
        vector<vector<int>>temp(R, vector<int>(C,0));

        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                
                if(map[r][c]==-1 || map[r][c]==0) continue;
                int cnt = 0;
                for(int d=0; d<4; d++){
                    int nxt_i = r+di[d];
                    int nxt_j = c+dj[d];

                    if(nxt_i < 0 || nxt_i >= R || nxt_j<0 || nxt_j >=C) continue;
                    if(map[nxt_i][nxt_j] == -1) continue;
                    temp[nxt_i][nxt_j] += int(map[r][c]/5);
                    cnt++;
                }
                temp[r][c] -= int(map[r][c]/5) * cnt;
            }
        }

        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                map[r][c] += temp[r][c];
            }
        }


        int cur_m1i = m1_i -1;
        int cur_m1j = 0;
        int cur_m2i = m2_i +1;
        int cur_m2j = 0;
        int dir=0;
        while(1){
            if(map[cur_m1i][cur_m1j]==-1) break;
            if((cur_m1i==0 && cur_m1j==0) || (cur_m1i==0 && cur_m1j==C-1) ||(cur_m1i==m1_i && cur_m1j==C-1) || (cur_m1i==m1_i && cur_m1j==0) ){
                dir ++;
            }
            int nxt_m1i= cur_m1i + form1i[dir];
            int nxt_m1j= cur_m1j + form1j[dir];

            if(map[nxt_m1i][nxt_m1j]==-1){
                map[cur_m1i][cur_m1j] = 0;
                break;
            }else{
                map[cur_m1i][cur_m1j] = map[nxt_m1i][nxt_m1j];
            }

            cur_m1i = nxt_m1i;
            cur_m1j = nxt_m1j;

        }
        dir = 0;
        while(1){
            if(map[cur_m2i][cur_m2j]==-1) break;
            if((cur_m2i==m2_i && cur_m2j==0) || (cur_m2i==m2_i && cur_m2j==C-1) ||(cur_m2i==R-1 && cur_m2j==C-1) || (cur_m2i==R-1 && cur_m2j==0) ){
                dir ++;
            }
            int nxt_m2i= cur_m2i + form2i[dir];
            int nxt_m2j= cur_m2j + form2j[dir];

            if(map[nxt_m2i][nxt_m2j]==-1){
                map[cur_m2i][cur_m2j] = 0;
                break;
            }else{
                map[cur_m2i][cur_m2j] = map[nxt_m2i][nxt_m2j];
            }

            cur_m2i = nxt_m2i;
            cur_m2j = nxt_m2j;

        }

    }
    int ans = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            ans+=map[i][j];
        }
        
    }
    cout << ans+2;

}