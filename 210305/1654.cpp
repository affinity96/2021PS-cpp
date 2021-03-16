#include <iostream>
#include <vector>


using namespace std;
int K, N;

vector<long long>lan;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N;
    long long l = 1;
    long long r = 0;
    for(int i=0; i<K; i++){
        int a; cin >> a;
        lan.push_back(a);
        if(r < a) r = a;
    }
    long long ans = 0;
    while(l<=r){
        long long mid = (l+r)/2;
        int mok = 0;
        for(int k=0; k<K; k++){
            mok += lan[k]/mid;
        }
        if(mok < N){
            r = mid-1;
        }else if(mok >= N){
            if (ans < mid) ans = mid;
            l = mid+1;
        }
        
    }
    cout << ans;

}