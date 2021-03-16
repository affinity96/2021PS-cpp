#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000001
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    vector <bool> nums(MAX, true);
    nums[0] = false;
    nums[1] = false;
    for(int i=2; i<MAX; i++){
        if(nums[i]){
            if(pow(i,2)>MAX) break;
            for(int j=pow(i,2); j<MAX; j+=i){
                nums[j] = false;
            }
        }
    }

    while(1){
        int even; cin >> even;
        if(even == 0) break;
        for(int i=3; i<MAX; i++){
            if(nums[i]){
                if(even - i < 0){
                    cout << "Goldbach's conjecture is wrong.\n";
                    break;
                }else{
                    if(nums[even-i]){
                        cout << even << " = " << i << " + " << even-i << "\n";
                        break;
                    }
                }
            }
        }
    }

}