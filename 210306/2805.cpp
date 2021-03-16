#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<long long>tree;

bool possible(long long t){
    long long namu = 0;
    for(int n=0; n<N; n++){
        if(tree[n] > t){
            namu += (tree[n] - t);
        }
    }
    if(namu >= M){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    long long l = 1;
    long long r = 0;
    for(int n=0; n<N; n++){
        long long elem; cin >> elem;
        tree.push_back(elem);
        if(r<elem) r = elem;
    }
    long long ans = 0;
    while(l<=r){
        long long m = (l+r)/2;
        if(possible(m)){
            if(ans < m) ans = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }

    cout << ans;
    
    
}