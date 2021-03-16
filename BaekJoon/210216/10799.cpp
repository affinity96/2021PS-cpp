#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    stack<char>s;
    string str; cin >> str;
    int flag = 0;
    int ans_ = 0;
    int answer = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='('){
            s.push(1);
            flag=0;
        }else{
            if(s.size()!=0){
                s.pop();
                if(!flag){
                    if(s.size()!=0){
                        answer += s.size();
                  
                    }
                    
                }else{
                    answer++;

                }
            }
            flag=1;
            
        }
    }
    cout << answer ;
}