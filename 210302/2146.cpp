#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N;
int ans = 200;
vector<vector<int>>graph;
vector<vector<int>>visited;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int n, int m, int i){
    visited[n][m] = i;
    for(int d=0; d<4; d++){
        int nx = n+dx[d]; int ny = m + dy[d];
        if(nx < 0 | nx >= N | ny < 0 | ny >= N) continue;
        else{
            if(!visited[nx][ny] && graph[nx][ny] == 1){
                visited[nx][ny] = i;
                dfs(nx, ny, i);
            }
        }
    }
}
int bfs(int i, vector<vector<int>>v2){
    int count = 0;
    queue<pair<int, int>>q;
    for(int a=0; a<N; a++){
        for(int b=0; b<N; b++){
            if(v2[a][b] == i){
                q.push(make_pair(a,b));
            }
        }
    }
    
    while(!q.empty()){
        int size = q.size();
        for(int s=0; s<size; s++){
            int fx = q.front().first;
            int fy = q.front().second;
            q.pop();

            for(int d=0; d<4; d++){
                int nx = fx+dx[d]; int ny = fy + dy[d];
                if(nx < 0 | nx >= N | ny < 0 | ny >= N) continue;
                else{
                    if(v2[nx][ny] == 0){
                        v2[nx][ny] = i;
                        q.push(make_pair(nx, ny));
                    }else if(v2[nx][ny]!=0 && v2[nx][ny]!=i){
                        return count;
                    }
                }
            }
        }
        count ++;
    }
    
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    graph.assign(N, vector<int>(N));
    visited.assign(N, vector<int>(N, 0));
    for(int n=0; n<N; n++){
        for(int m=0; m<N; m++){
            cin >> graph[n][m];
        }
    }
    int cnt=1;
    for(int n=0; n<N; n++){
        for(int m=0; m<N; m++){
            if(graph[n][m] && !visited[n][m]){
                dfs(n, m,cnt);
                cnt++;
            }
        }
    }

    for(int i=1; i<cnt; i++){
        vector<vector<int>>v2;
        v2.assign(visited.begin(), visited.end());
        
        ans = min(ans, bfs(i,v2));
    }
   
      
    

    cout << ans << "\n";

}