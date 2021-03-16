#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001
using namespace std;
int N;
vector<vector<pair<int, int>>>graph(MAX);
vector<bool>visited(MAX);
vector<int>dist(MAX);

void bfs(int a){
    queue<int>q;
    q.push(a);
    visited[a] = true;
    while(!q.empty()){
        int fro = q.front();
        q.pop();
        for(auto& n : graph[fro]){
            if(!visited[n.first]){
                q.push(n.first);
                visited[n.first] = true;
                dist[n.first] = dist[fro] + n.second;
            }
         
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int n=0; n<N-1; n++){
        int par, chi, dis;
        cin >> par >> chi >> dis;
        graph[par].push_back(make_pair(chi,dis));
        graph[chi].push_back(make_pair(par,dis));
    }

    bfs(1);
    int start_index = 1;
    int start_dist = 0;
    for(int i=1; i<=N; i++){
        if(dist[i] > start_dist){
            start_index = i;
            start_dist = dist[i];
        }
    }
    visited.assign(MAX, false);
    dist.assign(MAX, 0);

    bfs(start_index);
    int max = dist[1];
    for(int i=2; i<=N; i++){
        if(dist[i]>max){
            max = dist[i];
        }
    }

    cout << max;
}