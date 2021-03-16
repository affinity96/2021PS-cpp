#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    vector<int>nums(N);
    for(int n=0; n<N; n++){
        nums[n] = n+1;
    }
    cout << "<";
    int cur = M-1;
    int N_ = N;

    for(int n=0; n<N; n++){
        cout << nums[cur];
        if(n==N-1){cout << ">\n";}
        else{
            cout << ", ";
        }

        nums.erase(nums.begin()+cur);
        cur+=(M-1);
        if(--N_ > 0){
            cur %= N_;
        }
    }
}