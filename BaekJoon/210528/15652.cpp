#include <iostream>
#include <vector>

using namespace std;
int N, M;
int arr[100];

void dfs(int n, int cnt){
    if(cnt == M ){
        for(int m=0; m<M; m++){
            cout << arr[m] << " ";
            
        }
        cout << "\n";
        return;
    }else{
        for(int i=n; i<=N; i++){
            arr[cnt] = i;
            dfs(i, cnt+1); 
        }
    }

}
int main(){
    cin >> N >> M;
    dfs(1, 0);
}