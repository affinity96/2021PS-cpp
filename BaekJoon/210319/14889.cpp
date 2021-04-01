#include <iostream>
#include <vector>

using namespace std;
int N;
int max_cha = 100000;
vector<vector<int>>ability;
vector<bool>visited;

void dfs(int cur, int len){
    visited[cur] = true;
    if(len == N/2){
        vector<int>start;
        vector<int>link;
        for(int i=0; i<N; i++){
            if(visited[i]) start.push_back(i);
            else link.push_back(i);
        }
        int start_sum=0;
        int link_sum = 0;
        for(int i=0; i<N/2; i++){
            for(int j=0; j<N/2; j++){
                start_sum += ability[start[i]][start[j]];
                link_sum += ability[link[i]][link[j]];
            }
        }
        int cha=0;
        if(start_sum>=link_sum) cha = start_sum - link_sum;
        else cha = link_sum-start_sum;
        if(cha<max_cha){
            max_cha = cha;
        } 
        
    }else{
        for(int i=cur+1; i<N; i++){
            if(!visited[i]){
                dfs(i, len+1);
            }
        }
    }
    visited[cur] = false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    ability.assign(N, vector<int>(N));
    visited.assign(N,false);
    for(int n=0; n<N; n++){
        for(int m=0; m<N; m++){
            cin >> ability[n][m];

        }
    }

    dfs(0,1);

    cout<<max_cha;
}