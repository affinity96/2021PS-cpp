#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string N; 

bool compare(char i, char j){
    return j < i;
}
int main(){
    cin >> N;
    int sum =0;
    int zero = 0;
    for(int n=0; n<N.size(); n++){
        int target = N[n]-'0';
        if(target == 0) zero = 1;
        sum += target;
    }

    if(!zero){
        cout << -1;
        return 0;
    }
    if(sum % 3 !=0){
        cout << -1; 
        return 0;
    }
    else{
        sort(N.begin(), N.end(), compare);
        cout << N;
    }

}