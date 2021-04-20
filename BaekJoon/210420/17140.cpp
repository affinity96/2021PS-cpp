#include <iostream>
#include <vector>

using namespace std;
int R, C, K;
int row = 3, col = 3;
vector<vector<int>>A(100, vector<int>(100));
int main(){
    cin >> R >> C >> K;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> A[i][j];
        }
    }
    int ans = 0;

    while(ans<=100){
        if(A[R-1][C-1]==K) break;
        
        if(row>=col){
            
            int max_col = 0;
            for(int i=0; i<row; i++){
                vector<int>count(101,0);
                for(int j=0; j<col; j++){
                    count[A[i][j]]++;
                    A[i][j] = 0;
                }
                vector<int>temp;
                int cnt=0;
                for(int a=1; a<=100; a++){
                    for(int b=1; b<=100; b++){
                        if(count[b]==a){
                            temp.push_back(b);
                            temp.push_back(a);
                            cnt+=2;
                        }
                    }
                }
                if(temp.size()>100){
                    for(int k=0; k<100; k++){
                        A[i][k] = temp[k];
                    }
                }else{
                    for(int k=0; k<temp.size(); k++){
                        A[i][k] = temp[k];
                    }

                }
                
                
                
                if(cnt>=max_col){
                    max_col = cnt;
                }


            }
            
            col = max_col;
            // cout << col<<"col!";
        }else{
            int max_row = 0;
            for(int i=0; i<col; i++){
                
                vector<int>count(101,0);
                for(int j=0; j<row; j++){
                    count[A[j][i]]++;
                    A[j][i] = 0;
                }
                vector<int>temp;
                int cnt=0;
                for(int a=1; a<=100; a++){
                    for(int b=1; b<=100; b++){
                        if(count[b]==a){
                            temp.push_back(b);
                            temp.push_back(a);
                            cnt+=2;
                        }
                    }
                }
                if(temp.size()>100){
                    for(int k=0; k<100; k++){
                        A[k][i] = temp[k];
                    }
                }else{
                    for(int k=0; k<temp.size(); k++){
                        A[k][i] = temp[k];
                    }
                    

                }
                
                
                
                if(cnt>=max_row){
                    max_row = cnt;
                }


            }

            row = max_row;
          //  cout << row<<"row!";
        }

        ans++;
    }


  

    if(ans>100){
        cout << -1;
    }else{
        cout << ans;
    }
    // cout << "\n";

    //  for(int i=0; i<10; i++){
    //     for(int j=0; j<10; j++){
    //         cout<< A[i][j]<<" ";
    //     }
    //         cout << "\n" ;

    // }

    // cout << col<<" " << row;
}