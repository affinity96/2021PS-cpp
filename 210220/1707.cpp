#include <iostream>
#include <vector>

using namespace std;
int T, V, E;
vector<vector<int>> graph;
vector<int>visited;

int ans_flag = 0;
void dfs(int v){
    for(auto &n: graph[v]){
        if(!visited[n]){
            visited[n] = visited[v] * -1;
            dfs(n);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>  T;

    for(int t=0; t<T; t++){
        cin>>V>>E;
        graph.assign(V+1, vector<int>(0));
        visited.assign(V+1, 0);
        ans_flag = 0;
        for (int e=0; e<E; e++){
            int a, b; cin>>a>> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1; i<=V; i++){
            if(!visited[i]){
                visited[i] = 1;
                dfs(i);
            }
        }
        for(int i=1; i<=V; i++){
            for(auto &a : graph[i]){
                if(visited[a] == visited[i]){
                    ans_flag = 1;
                    
                }
            }
        }
        
        if(ans_flag == 1){
            cout << "NO";
        }else{
            cout << "YES";
        }

        cout <<"\n";
    }    

    
}