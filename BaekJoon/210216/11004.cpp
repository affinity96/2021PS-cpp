#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, K; cin>> N >> K;
    vector<int>num;
    for(int n=0; n<N; n++){
        int a; cin >> a;
        num.push_back(a);
    }
    sort(num.begin(), num.end());
    cout << num[K-1];
}