#include <iostream>


using namespace std;
int N;

int factorial(int n){
    if(n == 1){
        return 1;
    }else{
        return (n*factorial(n-1));
    }
}

int main(){
    cin >> N;
    if(N==0) {
        cout << 1;
        return 0;
        
    };

    cout << factorial(N);
}