#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int N, M, V; 
vector <vector<int>> graph;
vector <bool> visited;

void dfs(int v){
    visited[v] = true;
    cout << v << " ";
    for(auto &a : graph[v]){
        if(!visited[a]){
            dfs(a);
        }

    }
    
}

void bfs(int v){
    queue <int> q;

    q.push(v);
    visited[v] = true;
    while (!q.empty()){
        int f = q.front();
        cout <<f<<" ";
        q.pop();
        for(auto &i:graph[f]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    cin >> N >> M >> V;
    graph.assign(N+1, vector<int>(0));
    visited.assign(N+1, false);
    for(int m=0; m<M; m++){
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
  
    dfs(V);
    cout << "\n";
    visited.assign(N+1, false);
    bfs(V);
}
