#include <iostream>
#include <vector>

using namespace std;
long long N, B, C;
vector<long long>v;
int main(){
    cin >> N;
    for(int n=0; n<N; n++){
       long long elem; cin >> elem;
       v.push_back(elem);
    }  
    cin >> B >> C;
    long long ans = N;
    for(int n=0; n<N; n++){
        
        if(v[n]>B){
            v[n]-=B;
            if(v[n]%C==0){
            ans += v[n]/C;
            }else{

                ans += v[n]/C + 1;
            }
        }
        
    }
    cout << ans;
}