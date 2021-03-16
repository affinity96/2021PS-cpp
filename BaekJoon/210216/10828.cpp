#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack <int> str;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N; cin >> N;
    for(int n=0; n<N; n++){
        string s; cin >> s; 
        if(s == "push"){
            int num; cin >> num;
            str.push(num);
        }else if(s=="top"){
            if(str.size()==0){
                cout <<-1<<"\n";
            }else{
                cout<<str.top()<<"\n";
            }
        }else if(s=="pop"){
            if(str.size()==0){
                cout <<-1<<"\n";
            }else{
                cout <<str.top()<<"\n";
                str.pop();
            }
        }else if(s=="empty"){
            if(str.size()==0){
                cout<<1<<"\n";
            }else{cout<<0<<"\n";}
        }else if(s=="size"){
            cout<<str.size()<<"\n";
        }
        else{
            return 0;
        }
    }
}