#include <iostream>
#include <vector>
#define MAX 20000001
#define PLUS 10000000
using namespace std;

vector <int> num(MAX);
int N, M;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int n=0; n<N; n++){
        int a; cin >> a;
        num[a+PLUS]++;
    }
    cin >> M;
    for(int m=0; m<M; m++){
        int a; cin >> a;
        if(num[a+PLUS]) cout << num[a+PLUS] << " ";
        else cout << 0 << " ";
    }
}