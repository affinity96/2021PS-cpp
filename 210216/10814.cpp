#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<int, string>a, pair<int, string>b){
    return a.first < b.first;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector <pair <int, string>>nums;
    int N; cin>> N;
    for (int n=0; n<N; n++){
        pair<int, string> num_elem;
        cin>>num_elem.first>>num_elem.second;
        nums.push_back(num_elem);
    }
    stable_sort(nums.begin(), nums.end(), compare);
    for(int n=0; n<N; n++){
        cout << nums[n].first << " " << nums[n].second << "\n";
    }
}