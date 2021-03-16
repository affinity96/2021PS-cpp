#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int>nums;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int n=0; n<N; n++){
        int a; cin >> a; nums.push_back(a);
    }
    for(int m=0; m<M; m++){
        int a; cin >> a; nums.push_back(a);
    }
    sort(nums.begin(), nums.end());

    for(int i=0; i<M+N; i++){
        cout << nums[i] <<" ";
    }

    
}