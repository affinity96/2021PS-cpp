#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    for(int t=0; t<T; t++){
        stack <char> s;
        int flag = 0;
        string str; cin>>str;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='('){
                s.push(1);
            }else{
                if(s.size()==0){
                    flag = 1;
                    continue;
                }else{
                    s.pop();
                }
            }
        }
        if(s.size()==0 && flag ==0){
            cout<<"YES"<<'\n';
            continue;
        }else{
            cout<<"NO"<<'\n';
            continue;
        }
    }

}