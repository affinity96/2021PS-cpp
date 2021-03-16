#include <iostream>
#include <vector>

using namespace std;
vector<bool>visited;
void dfs(vector<vector<int>>&graph,  int v){
    visited[v] = true;
    for(int n : graph[v]){
        if(!visited[n]){

            dfs(graph, n);
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    for(int t=0; t<T; t++){
        int N; cin >> N;
        int ans=0;
        vector<vector<int>>graph(N+1, vector<int>(0));
        visited.assign(N+1, false);
        for(int n=1; n<=N; n++){
            int gelem; cin>>gelem;
            graph[n].push_back(gelem);
        }

        for(int n=1; n<=N; n++){
            if(!visited[n]){
                dfs(graph, n);
                ans ++ ;
            }
        }
        cout << ans << "\n";
    }
}
        