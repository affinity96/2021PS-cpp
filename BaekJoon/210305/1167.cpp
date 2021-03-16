#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int V;
vector<vector<pair<int, int>>> graph(MAX);
vector<bool>visited;
vector<int>dist;

void dfs(int v){
    visited[v] = true;    
    for(auto& i : graph[v]){
        
        if(!visited[i.first]){
            
            dist[i.first] = dist[v] + i.second;
            
            dfs(i.first);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V;
    visited.assign(V+1, false);
    dist.assign(V+1, 0);
    for(int v=0; v<V; v++){
        int i, a, b;
        cin >> i;
        while(1){
            cin >> a;
            if(a == -1) break;
            else{
                cin >> b;
                graph[i].push_back(make_pair(a, b));
            }
        }
    }
    dfs(1);
    int start_dist = 0;
    int start_index = 1;
    for(int i=1; i<=V; i++){

        if(dist[i] > start_dist){
            start_index = i;
            start_dist = dist[i];
        }
    }
    visited.assign(V+1, false);
    dist.assign(V+1, 0);
    
    dfs(start_index);
    int ans = dist[1];
    for (int i = 2; i <= V; i++)
    {
        if (ans < dist[i]) ans = dist[i];
    }

    cout << ans << "\n";
}
