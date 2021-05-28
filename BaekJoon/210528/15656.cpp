#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int N, M;
int arr[100];
vector<int>nums;

void dfs(int cnt){
    if(cnt == M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";

        }
        cout << "\n";
        return;
    }else{
        for(int i=0; i<N; i++){
            arr[cnt] = nums[i];
            dfs(cnt+1);
        }
    }
}

int main(){
    cin >> N >>M;
    for(int n=0; n<N; n++){
        int elem; cin >> elem;
        nums.push_back(elem);
    }

    sort(nums.begin(), nums.end());
    dfs(0);
}