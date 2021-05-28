#include <iostream>
#include <vector>

using namespace std;
int N, M;
int arr[100] ={0, };

void dfs(int cnt){
    if(cnt == M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";

        }
        cout << "\n";
        return;
    }else{
        for(int i=1; i<=N; i++){
            arr[cnt] = i;
            dfs(cnt+1);
        }
    }
    return;
}


int main(){
    cin >> N >> M;

    dfs(0);
}