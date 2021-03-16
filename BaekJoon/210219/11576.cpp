#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A, B; cin >> A >> B;
    
    int M; cin>>M;
    int M_ = M-1;
    int pure = 0;
    for(int m=0; m<M; m++){
        int num; cin>>num;
        pure += num * pow(A, M_);
        M_--;
    }

    stack<int>s;
    if(pure < B) cout << pure; 
    else{
        while(pure >= B){
        int na = pure%B;
        int mok = pure/B;
        pure = mok;
        s.push(na);
        if(pure<B) s.push(mok);
     }
     
    }
    int a = s.size();
    for(int i=0; i<a; i++){
        cout << s.top() << " ";
        s.pop();
    }


    
}