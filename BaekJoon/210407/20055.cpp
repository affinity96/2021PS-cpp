#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
vector<int>container;
vector<bool>robot;
int main(){
    cin >> N >> K;
    container.assign(2*N+1, 0);
    robot.assign(2*N+1, false);
    for(int n=1; n<=2*N; n++){
        cin >> container[n];
    }
    
    int upside = 1;
    int downside = N;
    int ans = 0;
    int zcnt = 0;
    
    while(1){
        ans++;
        if(upside == 1) upside = 2*N;
        else upside--;
        if(downside == 1) downside = 2*N;
        else downside--;
        
        
        if(robot[downside]) robot[downside] = false;

        int cur_idx = downside;
        for(int i=0; i<N-1; i++){
           
            int front_idx;
            if(cur_idx==1){
                front_idx = 2*N;
            }else{
                front_idx = cur_idx-1;
            }

            if(robot[front_idx] && (!robot[cur_idx]) && (container[cur_idx]>=1)){
                robot[front_idx] = false;
                robot[cur_idx] = true;
                container[cur_idx]--;
                if(cur_idx == downside){
                    robot[cur_idx] = false;
                }
            }

            
            cur_idx = front_idx;
        }

        if((!robot[upside]) && (container[upside] >=1)){
            robot[upside] = true;
            container[upside] --;
        }
        
        if(count(container.begin(), container.end(), 0)-1 >= K){
            
            break;
        } 

    }



    cout << ans;
}