#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int w, h;
vector<vector<int>>graph;
vector<vector<bool>>visited;
int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};
void dfs(int i, int j){
    visited[i][j] = true;
    for(int d=0; d<8; d++){
        int ni = i+dx[d];
        int nj = j+dy[d];
        if(ni < 0 || ni > h-1 || nj < 0 || nj > w-1) continue;
        else{
            if(!visited[ni][nj] && graph[ni][nj]==1) dfs(ni, nj);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    while(1){
        
        cin >> w >>h;
        int cnt = 0;
        if(w==0&&h==0) return 0;

        graph.assign(h, vector<int>(w,0));
        visited.assign(h, vector<bool>(w, false));

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> graph[i][j];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(!visited[i][j] && graph[i][j] == 1){
                    dfs(i,j);
                    cnt ++;
                }
            }
        }

        cout << cnt << "\n";
    }
}