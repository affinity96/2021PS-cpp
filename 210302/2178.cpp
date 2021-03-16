#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0}; 
vector <string> graph;
vector <vector<int>>visited;

void bfs(){
    queue <pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0][0] = 1;
    while(!q.empty()){
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int nx = fx + dx[d];
            int ny = fy + dy[d];
            if(nx<0 | nx>=N | ny<0 | ny>=M) continue;
            else{
                if(graph[nx][ny] == '1' && visited[nx][ny]==0){
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = visited[fx][fy] + 1;
                }
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;

    for(int n=0; n<N; n++){
        string elem;
        cin >> elem;
        graph.push_back(elem);
    }

    visited.assign(N, vector<int>(M,0));

    bfs();
    cout << visited[N-1][M-1];
}