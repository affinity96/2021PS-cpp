#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<int, int>&a, pair<int, int>&b){
    if(a.second == b.second){
        return a.first<b.first;
    }else{
        return a.second<b.second;
    }
}
int main(){
    int N; cin >> N;
    vector<pair<int, int>> num;
    for(int n=0; n<N; n++){
        pair<int, int> num_elem;
        cin >> num_elem.first >> num_elem.second;
        num.push_back(num_elem);
    }
    sort(num.begin(), num.end(), compare);
    for(int n=0; n<N; n++){
        cout << num[n].first << " "<<num[n].second << "\n";
    }
}