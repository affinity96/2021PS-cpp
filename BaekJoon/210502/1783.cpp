#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    if(N==1){
        cout << 1;
        return 0;
    }else if(N==2){
        if(M<=2){
            cout << 1;
            return 0;
        }
        else if(M<5){
            cout << 2;
            return 0;
        }else{
            cout << 3;
            return 0;
        }
    }else{
        if(M<=4){
            cout << M;
            return 0;
        }else if(M==5){
            cout << 4; 
            return 0;
        }else{
            cout << M-2;
            return 0;
        }
    }
}