#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<pair<int, int>>house;
vector<pair<int, int>>chicken;
vector<pair<int, int>>candidate;
vector<bool>visited;
int ans = 10000000;

void dfs(int cnt, int cur){
    if(cnt == M){
        int semi_min = 0;
        for(int h=0; h<house.size(); h++){
            int temp_min = 10000000;
            int x1 = house[h].first;
            int y1 = house[h].second;
            for(int c=0; c<candidate.size(); c++){
                int x2 = candidate[c].first;
                int y2 = candidate[c].second;

                int length = abs(x1-x2) + abs(y1-y2);
                if(temp_min >length){
                    temp_min = length;
                }
            }

            semi_min += temp_min;
        }

        if(semi_min < ans){
            ans = semi_min;
        }

        // for(int c=0; c<candidate.size(); c++){
        //     cout << candidate[c].first << candidate[c].second << " ";       
        // }
        // cout << "!";

        return;
    }else{

        for(int i=cur; i<chicken.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                candidate[cnt] = chicken[i];
                dfs(cnt+1, i);
                visited[i] = false;
            }
        }
    }
}

int main(){
    cin >> N >> M ;
    for(int n=0; n<N; n++){
        for(int m=0; m<N; m++){
            int elem;
            cin >> elem;
            if(elem == 1){
                house.push_back(make_pair(n, m));
            }else if(elem == 2){
                chicken.push_back(make_pair(n, m));
            }
        }
    }
    candidate.assign(M, make_pair(-1, -1));
    visited.assign(chicken.size(), false );
    

    dfs(0, 0);

    cout << ans;    
}