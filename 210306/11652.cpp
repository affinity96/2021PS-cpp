#include <iostream>
#include <vector>
#include <map>
using namespace std;
map <long long, int> v;
int N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int n=0; n<N; n++){
        long long num; cin >> num;
        if(v.find(num) == v.end()){
            v.insert(make_pair(num, 1));
        }else{
            v[num]++;
        }
    }
    //map<long long, int> :: iterator iter;
    long long max_elem = 0;
    int max = 0;
    for(auto iter = v.begin(); iter!=v.end(); iter++){
        if((iter -> second) > max){
            max = iter -> second;
            max_elem = iter->first;
        }else if((iter->second) == max){
            if(max_elem > iter->first){
                max_elem = iter->first;
                max = iter->second;
            }
        }
        
    }

    cout << max_elem;
}