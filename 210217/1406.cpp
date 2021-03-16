#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack <char> l, r;
    string str; cin>>str;
    for(auto &a : str){
        l.push(a);
    }
    int N; cin>>N;
    for(int n=0; n<N; n++){
       char ch; cin>>ch;
       if(ch=='L'){
           if(!l.empty()){
               r.push(l.top());
               l.pop();
           }
       }else if(ch=='D'){
           if(!r.empty()){
               l.push(r.top());
               r.pop();
           }
       }else if(ch=='B'){
           if(!l.empty()){
               l.pop();
           }
       }else{
           char c; cin >> c;
           l.push(c);
       }
    }
    while(!(l.empty())){
        r.push(l.top());
        l.pop();
    }
    while(!(r.empty())){
        cout << r.top();
        r.pop();
    }
}