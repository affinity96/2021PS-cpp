#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int N, M;
int arr[100] = {0, };
bool visited[10001] = {false, };
vector <int> nums;
void dfs(int idx, int cnt){
    if(cnt == M){
        for(int i=0; i<M; i++){
            cout << arr[i] <<" ";

        }
        cout << "\n";
        return;
    }else{
        for(int i=idx; i<N; i++){
            if(!visited[nums[i]]){
                visited[nums[i]] = true;
                arr[cnt] = nums[i];
                dfs(i, cnt+1);
                visited[nums[i]] = false;
            }
        }
    }
}
int main(){
    cin >> N >> M;

    for(int n=0; n<N; n++){
        int elem; cin >> elem;
        nums.push_back(elem);
    }
    sort(nums.begin(), nums.end());
    dfs(0, 0);
}