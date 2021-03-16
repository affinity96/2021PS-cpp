#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, N; cin >> M >> N;
    vector <bool> num (N+1, true);
    num[0] = false;
    num[1] = false;
    for(int i=2; i<N+1; i++){
        if(num[i]){
            for(int j=pow(i,2); j<N+1; j=j+i){
                if( (pow(i,2)) > MAX) break;
                else{
                    num[j] = false;
                }
            }
        }
    }

    for(int i=2; i<N+1; i++){
        if(num[i]&&i>=M){
            cout << i << "\n";
        }
    }
}