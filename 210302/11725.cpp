#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>>graph;
vector<bool>visited;
vector<int>par;
int N;

void dfs(int a){
    visited[a] = true;
    for(int next : graph[a]){
        if(!visited[next]){
            par[next] = a;
            dfs(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    graph.assign(N+1, vector<int>(0));
    visited.assign(N+1,false);
    par.assign(N+1, 0);
    for(int n=0; n<N; n++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);

    for(int i=2; i<=N; i++){
        cout << par[i] << "\n";
    }
}