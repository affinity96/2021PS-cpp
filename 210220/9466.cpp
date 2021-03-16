#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;
int T, N, cnt;
vector <int> graph;
vector <bool> visited;
vector <bool> check;

void dfs(int v){
    visited[v] = true;
    int nxt = graph[v];
    if(!visited[nxt]){
        dfs(nxt);
    }else{
            if(!check[nxt]){
                for(int i=nxt; i!=v; i=graph[i]){
                    cnt ++;
                 }
            cnt++;
        }
        
    }
    check[v] = true;
}
int main(){
   
    cin >> T;
    for(int t=0; t<T; t++)
    {
        cin >> N;
        cnt = 0;
        visited.assign(MAX, false);
        graph.assign(MAX,0);
        check.assign(MAX, false);

        for(int n=1; n<=N; n++){
            cin >> graph[n];
        }
        for(int n=1; n<=N; n++){
            if(!visited[n]){
                dfs(n);
            }
        }
        cout << N-cnt<<"\n";
        

    }

    
}