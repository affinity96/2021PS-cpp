#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int>nums;
int arr[100] = {0, };
bool visited[10001] = {false, };
void dfs(int cnt){
    if(cnt == M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }else{
        for(int i=0; i<N; i++){
            if(!visited[nums[i]]){
                visited[nums[i]] = true;
                arr[cnt] = nums[i];
                dfs(cnt+1);
                visited[nums[i]] = false;
            }
        }
    }
}
int main(){
    cin >> N >> M;
    for(int n=0; n<N; n++){
        int num; cin >> num;
        nums.push_back(num);

    }
    sort(nums.begin(), nums.end());
    dfs(0);
}