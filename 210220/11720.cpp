#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int v){
    visited[v] = true;
    for(auto &n : graph[v]){
        if(!visited[n]){
            dfs(n);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> N >> M;
    graph.assign(N+1, vector<int>(0));
    visited.assign(N+1, false);
    for(int m=0; m<M; m++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<N+1; i++){
        if(!visited[i]){
            dfs(i);
            ans ++;

        }
    }

    cout << ans;
}