#include <iostream>
#include <vector>
#define MAX 100
using namespace std;
int N, M;
vector <int> nums;
vector <bool> visited;
int arr[MAX];
void dfs(int cnt){
    
    if(cnt == M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";

        }
        cout << "\n";
        return;
    }else{
        for(int i=1; i<=N; i++){
            if(!visited[i]){
                visited[i] = true;
                arr[cnt] = i;
                dfs(cnt+1);
                visited[i] = false;
            }
        }
    }

}
int main(){
    cin >> N >> M;

    nums.assign(N, 0);
    for(int n=0; n<N; n++){
        nums[n] = n+1;
    }
    visited.assign(N+1, false);
    dfs(0);
}