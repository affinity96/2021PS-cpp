#include <iostream>
#include <vector>
#include <cstring>

#define MAX 500
using namespace std;
int N, M;
int ans = 0;
bool visited[MAX+1][MAX+1];
vector<vector<int>>paper;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

void dfs(int i, int j, int cnt, int sum){
    visited[i][j] = true;

    if(cnt >= 4){
        
        if(sum > ans) {
            ans = sum;
            
        }
        
        return;
    }

    for(int d=0; d<4; d++){
        int ni = i+di[d];
        int nj = j+dj[d];
        if(ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
        if(visited[ni][nj]) continue;
        int nsum = sum + paper[ni][nj];
        dfs(ni, nj, cnt+1, nsum);
        visited[ni][nj] = false;
    }
    visited[i][j] = false;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    paper.assign(N, vector<int>(M));
    
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            cin >> paper[n][m];
        }
    }
    
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            
            dfs(n, m, 1, paper[n][m]);
            //ㅏ
            if(n<N-2 && m<M-1){
                int tmp = paper[n][m] + paper[n+1][m] + paper[n+2][m] + paper[n+1][m+1];
                if (ans < tmp) ans = tmp;
            }

            //ㅗ
            if(m>0 && m<M-1 && n<N-1){
                int tmp = paper[n][m] + paper[n+1][m-1] + paper[n+1][m] + paper[n+1][m+1];
                if (ans < tmp) ans = tmp;
            }

            //ㅓ
            if(m>0 && n<N-2){
                int tmp = paper[n][m] + paper[n+1][m] + paper[n+2][m] + paper[n+1][m-1];
                if (ans < tmp) ans = tmp;
            }

            // ㅜ
            if(m<M-2 && n<N-1){
                int tmp = paper[n][m] + paper[n][m+1] + paper[n][m+2] + paper[n+1][m+1];
                if (ans < tmp) ans = tmp;

            }
        }
    }

    cout << ans;

}