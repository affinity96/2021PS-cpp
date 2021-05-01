#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N = 9;
vector<vector<int>>edge(
    {
    vector<int>({0,2}), 
    vector<int>({2,1}),
    vector<int>({2,4}), 
    vector<int>({3,5}), 
    vector<int>({5,4}), 
    vector<int>({5,7}), 
    vector<int>({7,6}), 
    vector<int>({6,8})
    }
) ;

vector<vector<int>>map(N);
vector<bool>visited;
vector<int>nums;

int dfs(vector<vector<int>>map, int root, int count){
    visited[root] = true;
    count ++;
    for(int i=0; i<map[root].size(); i++){
        if(!visited[map[root][i]]){
            visited[map[root][i]] = true;
            count = dfs(map, map[root][i], count);
        }
    }
    return count ;


}
int main(){
    for(int i=1; i<edge.size(); i++){
        vector<int>find;
        for(int b=0; b<edge.size()-i; b++){
            find.push_back(0);
        }
        for(int a=0; a<i; a++){
            find.push_back(1);
        }
        do{
            vector<int>candidate;
            vector<vector<int>>temp(N);
            for(int h=0; h<find.size(); h++){
                if(find[h]){
                    candidate.push_back(h);
                }else{
                    temp[edge[h][0]].push_back(edge[h][1]);
                    temp[edge[h][1]].push_back(edge[h][0]);
                }
            }
            visited.assign(N, false);
            nums.assign(0,0);
            int cnt = 0;


            for(int n=0; n<N; n++){
                if(!visited[n]){
                    nums.push_back(dfs(temp, n, 0));

                    cnt++;
                }
            }

            if(cnt == 3){
                int flag = 0;
                int first = nums[0];
                for(int i=1; i<3; i++){
                    if(nums[i] != first){
                        flag = 1;
                    }
                }
                if(flag == 0){
                    for(int i=0; i<candidate.size(); i++){
                        cout << candidate[i]<< " ";
                        
                    }
                    return 0;

                }
            }

        }while(next_permutation(find.begin(), find.end()));

    }
}