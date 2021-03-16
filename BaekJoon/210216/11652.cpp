#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<long long, int>nums;
    int N; cin >> N;
    int max = 0;
    long long max_elem = 0;
    for(int n=0; n<N; n++){
        long long nums_elem;
        cin >> nums_elem;
        if(nums.find(nums_elem) == nums.end()){
            nums.insert(make_pair(nums_elem,1));

        }else{
            nums.at(nums_elem) = nums.at(nums_elem)+1;
                    
        }
     }
    for (auto it = nums.begin(); it!=nums.end() ; it ++){
        if (it->second > max){
            max_elem = it->first;
            max = it->second;
        }else if(it ->second == max){
            if(max_elem > it->first){
                max_elem = it -> first;
                max = it->second;
            }
        }
    }
     cout << max_elem;

}