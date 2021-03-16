#include <iostream>
#include <vector>

using namespace std;

long long func(long long n, long long x){
    long long num=0;
    for(long long i=x; n/i>=1; i *=x){
        num += n/i;
    }
    return num;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    long long n, m; cin >> n >> m;

     if(n==m || m==0){
        cout << 0;
        return 0;
    }
  
    long long fi = func(n,5)-func(m,5)-func(n-m,5);
    long long tw = func(n,2)-func(m,2)-func(n-m,2);

    cout << min(fi,tw);
   
}