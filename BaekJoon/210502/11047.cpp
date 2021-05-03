#include <iostream>
#include <vector>

using namespace std;
int N, K;
vector<int>coin;
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    cin >> N >> K;
    coin.assign(N, 0);
    for(int n=0; n<N; n++) cin >> coin[n];
    int cnt = 0;
    for(int n=N-1; n>=0; n--){
        int dnum = coin[n];
        int mok = K/dnum;
        int na = K%dnum;
        K=na;
        cnt += mok;
    }
    cout << cnt;

}