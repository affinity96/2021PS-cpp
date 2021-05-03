#include <iostream>
#include <vector>

using namespace std;
int N, M, K;
int main(){
    cin >> N >> M >> K;

    for(int k=0; k<K; k++){
        if(N>= M*2){
            N--;
        }else{
            M--;
        }
    }

    int ans = N/2 > M ? M : N/2;
    cout << ans;
}