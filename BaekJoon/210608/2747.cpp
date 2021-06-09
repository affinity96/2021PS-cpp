#include <iostream>
#include <vector>

using namespace std;
int N;


int main(){
    cin >> N;
    
    int first = 0;
    int second = 1;
    int target = 0;
    if(N==1){
        cout << 1;
        return 0;
    }
    for(int n=1; n<N; n++){
        target = first + second;
        first = second;
        second = target;
    }

    cout << target;
    
}