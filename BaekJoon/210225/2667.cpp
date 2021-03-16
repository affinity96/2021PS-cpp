#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N;
vector <string> graph;
vector <vector<bool>> visited;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int cnt = 0;
void dfs(int i, int j){
    visited[i][j] = true;
    for(int d=0; d<4; d++){
        if(i+dx[d] < 0 || i+dx[d] > N-1 || j+dy[d] < 0 || j+dy[d]>N-1 ) continue;
        else{
            if(!visited[i+dx[d]][j+dy[d]] && graph[i+dx[d]][j+dy[d]] == '1'){
                dfs(i+dx[d], j+dy[d]);
                cnt ++;
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    vector<int> ans;
    cin >> N;
    for(int n=0; n<N; n++){
        string elem; cin>>elem;
        graph.push_back(elem);
    }
    visited.assign(N, vector<bool>(N));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j] && graph[i][j]=='1'){
                cnt = 0;
                dfs(i,j);
                ans.push_back(++cnt);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << "\n";
    }
}