#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, C;
vector<long long>house;

bool possible(long long m){
    int cnt = 1;
    long long cur = house[0];
    for(int i=1; i<N; i++){
        if(house[i] - cur >= m){
            cnt ++;
            cur = house[i];
        }
    }
    if(cnt < C){
        return false;
    }else{
        return true;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C;
    long long l = 1;
    long long r = 0;
    for(int n=0; n<N; n++){
        long long elem; cin >> elem;
        house.push_back(elem);
    }
    sort(house.begin(),house.end());
    r = house[N-1] - house[0];
    long long ans=0;
    while(l<=r){
        long long m=(l+r)/2;
        if(possible(m)){
            if(ans < m) ans = m;
            l = m+1;
        }else{
            r = m-1;
        }
    }
    cout << ans;
}