#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int>nums(10001,0);
    for(int n=0; n<N; n++){
        int num_elem;
        cin>>num_elem;
        nums[num_elem]++;
    }
    for(int n=0; n<10001; n++){
        if(nums[n]!=0){
            for(int i=0; i<nums[n]; i++){
                cout << n << "\n";
            }
        }
    }
}