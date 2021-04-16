#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, C;
int cur_idx = 0;
vector <vector<int>> map;
vector <vector<bool>> visited;
vector <vector<int>> guest;
int taxi_i, taxi_j;
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};

void find_guest(){
    int flag =0;
    int cnt = 0;
    vector<pair<int, int>>temp;
    queue <pair<int, int>> q;
    visited.assign(N+1, vector<bool>(N+1));

    q.push(make_pair(taxi_i, taxi_j));
    visited[taxi_i][taxi_j] = true;

    while(!q.empty()){
        int size = q.size();
        for(int s=0; s<size; s++){
            int cur_i = q.front().first;
            int cur_j = q.front().second;
            if(map[cur_i][cur_j]!=0 && map[cur_i][cur_j] != -1){
                temp.push_back(make_pair(cur_i, cur_j));
            }
            q.pop();
            for(int d=0; d<4; d++){
                int nxt_i = cur_i + di[d];
                int nxt_j = cur_j + dj[d];
                if(nxt_i <= 0 || nxt_i > N || nxt_j <= 0 || nxt_j > N) continue;
                if(visited[nxt_i][nxt_j] || map[nxt_i][nxt_j] == -1) continue;
                q.push(make_pair(nxt_i, nxt_j));
                visited[nxt_i][nxt_j] = true;
            }
        }

        if(!temp.empty()){
            C-=cnt;
            sort(temp.begin(), temp.end());
            taxi_i = temp[0].first;
            taxi_j = temp[0].second;
            cur_idx = map[taxi_i][taxi_j];
            map[taxi_i][taxi_j] = 0;
            flag = 1;
            return;
            
        }
        cnt++;
    }

    if(!flag){
        C = -1;
        return;
    }
}


void drive(){
    int flag = 0;
    int dest_i = guest[cur_idx][2];
    int dest_j = guest[cur_idx][3];
  

    int cnt = 0;
    visited.assign(N+1, vector<bool>(N+1));
    queue <pair<int, int>> q;
    
    q.push(make_pair(taxi_i, taxi_j));
    visited[taxi_i][taxi_j] = true;

    while(!q.empty()){
        int size = q.size();
        
        for(int s=0; s<size; s++){
            int cur_i = q.front().first;
            int cur_j = q.front().second;
            if(cur_i == dest_i && cur_j == dest_j){

                if(C - cnt <0){
                    C = -1;
                    flag = 1;
                    return;
                }else{
                    C += cnt;
                    taxi_i = cur_i;
                    taxi_j = cur_j;
                    flag = 1;
                    return;
                }
            }
            q.pop();

            for(int d=0; d<4; d++){
                int nxt_i = cur_i + di[d];
                int nxt_j = cur_j + dj[d];

                if(nxt_i <= 0 || nxt_i > N || nxt_j <=0 || nxt_j >N) continue;
                if(visited[nxt_i][nxt_j] || map[nxt_i][nxt_j] == -1) continue;
                

                q.push(make_pair(nxt_i, nxt_j));
                visited[nxt_i][nxt_j] = true;
            }
        }
        cnt ++;
        
    }

    if(!flag){
        C=-1;
        return;
    }
}

int main(){
    cin >> N>>M>>C;
    map.assign(N+1, vector<int>(N+1));
    guest.assign(M+1, vector<int>(4));
    for(int n=1; n<=N; n++){
        for(int m=1; m<=N; m++){
            cin >> map[n][m];
            if(map[n][m]==1){
                map[n][m] = -1;
            }
        }
    }

    cin>>taxi_i>>taxi_j;
    for(int n=1; n<=M; n++){
        for(int m=0; m<4; m++){
            cin>>guest[n][m];
            
        }

        map[guest[n][0]][guest[n][1]] = n;     
    }

    for(int n=0; n<M; n++){
        find_guest();

        if(C<0){
            cout<<-1;
            return 0;
        }
        drive();

        if(C<0){
            cout<<-1;
            return 0;
        }
    }
    

    cout << C;


}