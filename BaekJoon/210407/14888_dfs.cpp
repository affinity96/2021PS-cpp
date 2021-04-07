#include <iostream>
#include <vector>

using namespace std;

int max_ = -1000000001;
int min_ = 1000000001;
int N;
vector<int>nums;
vector<int>syms;
vector<int>visited;
void dfs(int num_idx, int sym_idx, int cnt, int result){
    if(cnt == N-1){
        if(result >= max_) max_ = result;
        if(result <= min_) min_ = result;
    }else{
        for(int i=0; i<N-1; i++){
            if(visited[i]) continue;
            else{
                int nresult = 0;
                if(syms[i]==0){
                    nresult = result + nums[num_idx];
                }else if(syms[i]==1){
                    nresult = result - nums[num_idx];
                }else if(syms[i]==2){
                    nresult = result * nums[num_idx];
                }else if(syms[i]==3){
                    nresult = result / nums[num_idx];
                }

                visited[i] = true;
                dfs(num_idx+1, i, cnt+1, nresult);
                visited[i] = false;
                
            }
        }
    }

    
}
int main(){
    cin >> N;
    for(int n=0; n<N; n++){
        int elem; cin>>elem;
        nums.push_back(elem);
    }
    
    for(int n=0; n<4; n++){
        int elem; cin>>elem;
        for(int e=0; e<elem; e++){
            if(n==0) syms.push_back(0);
            if(n==1) syms.push_back(1);
            if(n==2) syms.push_back(2);
            if(n==3) syms.push_back(3);
        }
        
    }
    visited.assign(N-1, false);
    dfs(1, 0, 0, nums[0]);
    cout << max_ <<"\n" << min_;
}