#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int M, N;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<int>>graph;
vector<vector<int>>visited;
queue<pair<int, int>>q;

void bfs(){
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        
        q.pop();

        for(int d=0; d<4; d++){
            int na = a+dx[d];
            int nb = b+dy[d];

            if(na < 0 || nb <0 || na>=N || nb >=M) continue;
            else{
                if(graph[na][nb] == 0){
                    graph[na][nb] = graph[a][b] + 1;
                    q.push(make_pair(na,nb));
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    graph.assign(N, vector<int>(M));
    visited.assign(N, vector<int>(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> graph[i][j];
            if(graph[i][j]==1){
                q.push(make_pair(i,j));
            }
        }
    }

    bfs();
    int max = -1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(graph[i][j] == 0){
                cout << -1; 
                return 0;
            }
            else if(graph[i][j] > max){   
                max = graph[i][j];
            }
        }
    }

    cout << max-1;
    
}