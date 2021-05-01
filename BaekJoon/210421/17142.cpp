#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
vector<pair<int, int>> candidate;
vector<vector<int>> map;
vector<int>result;
vector<int>can;
int two=0;
int wall = 0;

void bfs(){
    int all = N*N - wall - two;
    if(all == 0){
        result.push_back(0);
        return;
    }
    vector<vector<int>>visited(N, vector<int>(N, -1));
    queue<pair<int, int>>q;
    for(int c=0; c<can.size(); c++){
        if(can[c]){
            q.push(candidate[c]);
            visited[candidate[c].first][candidate[c].second] = 0;
        }

    }
        int cnt = 0;
        while(!q.empty()){
            
            int size = q.size();
            for(int s=0; s<size; s++){
                int cur_i = q.front().first;
                int cur_j = q.front().second;

                q.pop();

                for(int d=0; d<4; d++){
                    int nxt_i = cur_i + di[d];
                    int nxt_j = cur_j + dj[d];

                    if(nxt_i < 0 || nxt_i >= N || nxt_j <0 || nxt_j >=N) continue;
                    if(visited[nxt_i][nxt_j] !=-1) continue;
                    if(map[nxt_i][nxt_j] == 1) continue;

                    if(map[nxt_i][nxt_j]==2){
                        q.push(make_pair(nxt_i, nxt_j));
                        visited[nxt_i][nxt_j] = visited[cur_i][cur_j]+1;
                    }else{
                        q.push(make_pair(nxt_i, nxt_j));
                        visited[nxt_i][nxt_j] = visited[cur_i][cur_j]+1;
                        cnt++;
                    }
                    

                    if(cnt == all){
                        result.push_back(visited[nxt_i][nxt_j]);


                        // for(int i=0; i<N; i++){
                        //     for(int j=0; j<N; j++){
                        //         cout << visited[i][j]<<" ";
                        //     }
                        //     cout << "\n";
                        // }
                        // cout << "\n";
                    }
                }
            }
        }
    }

  



int main(){
    cin >> N >> M;
   
    
    map.assign(N, vector<int>(N));
    for(int n=0; n<N; n++){
        for(int m=0; m<N; m++){
            cin>>map[n][m];
            if (map[n][m] == 2){
                candidate.push_back(make_pair(n,m));
                two++;
            }else if( map[n][m]==1){
                wall++;
            }
        }
    }
    
    for(int m=0; m<two-M; m++){
        can.push_back(0);
    }
    for(int t=0; t<M; t++){
        can.push_back(1);
    }

    do{
        bfs();
        
    }while(next_permutation(can.begin(), can.end()));
    int answer = N*N+1;
    if(result.empty()){
        cout << -1;
        
    }else{
        for(int i=0; i<result.size(); i++){
            if(answer > result[i]) answer = result[i];
        }
        cout << answer;
    }
    
}