#include <iostream>
#include <vector>

using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<vector<int>>schedule(N+1, vector<int>(2));
    vector<int>dp(N+1);
    for(int n=1; n<N+1; n++){
        cin >> schedule[n][0] >> schedule[n][1];
    }
    if(schedule[1][0] > N){
        dp[1] = 0;
    }else{
        dp[1] = schedule[1][1];
    }
    
    for(int n=2; n<N+1; n++){
        if(schedule[n][0]+n > N+1){
            dp[n] = 0;
        }else{
            int cur = 0;
            for(int i=1; i<n; i++){
                if(n-i >= schedule[i][0] && cur < dp[i]){
                    cur = dp[i];
                }
            }
            dp[n] = schedule[n][1] + cur;
        }
    }
    int max = 0;
    for(int n=1; n<N+1; n++){
        if(max < dp[n]){
            max = dp[n];
        }
    }

    cout << max;
}