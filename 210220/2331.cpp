#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int A, P;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> P;
    vector<int>nums = {A, };
    vector<int>::iterator iter;
    bool flag = true;
    int cnt = 0;
    int index = 0;
    int nxt = 0;
    while(flag){
        int nxt = 0;
        while(A>0){
            int na = A%10;
            nxt += pow(na,P);
            A /= 10;
        }
        iter = find(nums.begin(), nums.end(), nxt);
        if(iter == nums.end()){
            nums.push_back(nxt);
            cnt++;
        }else{
            index = iter-nums.begin();
            flag = false;
            break;

        }
        A = nxt;
    }
    
    cout << index;
    
}