#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int N;
vector<vector<int>>map;
int ans = 10000;

int main(){
    cin >> N;
    map.assign(N+1, vector<int>(N+1));

    for(int n=1; n<=N; n++){
        for(int m=1; m<=N; m++){
            cin >> map[n][m];
        }
    }

    for(int x=1; x<=N-2; x++){
        for(int y=2; y<=N-1; y++){
            for(int d1=1; d1<=N-1; d1++){
                for(int d2=1; d2<=N-1; d2++){
                    if(x+d1+d2 > N) continue;
                    if(1>y-d1 || y+d2>N) continue;
                    // cout <<"!"<< x<<y<<d1<<d2<<"!";
                    vector<int>citizen = {0, 0, 0, 0, 0, 0};

                    for(int i=1; i<=N; i++){
                        for(int j=1; j<=N; j++){
                            int isfive = 0;
                            int plusd1 = 0;
                            int plusd2 = 0;
                            int d1flag = 0;
                            int d2flag = 0;
                            for(int f=0; f<d1+d2+1; f++){
                                if(i == x+f && y+plusd1 <= j && j<=y+plusd2){
                                    isfive = 1;
                                    // if(x==3 && y==5 && d1==2 && d2==1){
                                    //     cout<< i << j<< "!";

                                    // }
                                    break;
                                }
                                if(abs(plusd1) >= d1){
                                    d1flag = 1;
                                }
                                if(plusd2 >= d2){
                                    d2flag = 1;
                                }

                                if(d1flag){
                                    plusd1 ++;
                                }else{
                                    plusd1 --;
                                }

                                if(d2flag){
                                    plusd2 --;
                                }else{
                                    plusd2 ++;
                                }

                            }
                            if(isfive){
                                citizen[5]+=map[i][j];
                            }else{
                                if(i<x+d1 && j<=y){
                                    citizen[1]+=map[i][j];

                                }else if(i<=x+d2 && y<j){
                                    citizen[2]+=map[i][j];
                                }else if(x+d1<=i && j<y-d1+d2){
                                    citizen[3]+=map[i][j];
                                }else if(x+d2<i && y-d1+d2<=j){
                                    citizen[4]+=map[i][j];
                                    
                                }
                            }
                    }
                }
                    int temp_max = 0;
                    int temp_min = 10000;
                    for(int c=1; c<6; c++){
                        if(citizen[c] > temp_max){
                            temp_max = citizen[c];
                        }
                        if(citizen[c] < temp_min){
                            temp_min = citizen[c];
                        }
                    }
                    int temp_minus = temp_max-temp_min;

                    if(temp_minus < ans){
                        ans = temp_minus;
                        
                    }

                    
                }
            }
        }
    }

    cout << ans;


}