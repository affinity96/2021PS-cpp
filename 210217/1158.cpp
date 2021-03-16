#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int N,K; cin>>N>>K;
    queue<int>q;
    for(int n=1; n<=N; n++){
        q.push(n);
    }
    cout << '<';
    int cnt = 0;
    while(!q.empty()){
        cnt ++;
        if(cnt == K){
            if(q.size()==1){
                cout << q.front()<<">";
                q.pop();
                cnt = 0;
            }else{
                cout << q.front()<< ", ";
                q.pop();
                cnt = 0;
            }
        }else{
            q.push(q.front());
            q.pop();
        }
    }
}