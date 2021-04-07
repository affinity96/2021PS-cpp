#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int max_ = -1000000001;
int min_ = 1000000001;
int N;


int main(){
    vector<int>num;
    vector<int>sym;
    cin >> N;
    for(int n=0; n<N; n++){
        int elem; cin>>elem;
        num.push_back(elem);
    }
    
    for(int n=0; n<4; n++){
        int elem; cin>>elem;
        for(int e=0; e<elem; e++){
            if(n==0) sym.push_back(0);
            if(n==1) sym.push_back(1);
            if(n==2) sym.push_back(2);
            if(n==3) sym.push_back(3);
        }
        
    }

    do{
        int cur = num[0];
        for(int i=0; i<sym.size(); i++){
            if(sym[i]==0){
                cur = cur+num[i+1];
            }else if(sym[i]==1){
                cur = cur-num[i+1];
            }else if(sym[i]==2){
                cur = cur*num[i+1];
            }else if(sym[i]==3){
                cur = cur/num[i+1];
            }

        }

            if(cur >= max_) max_ = cur;
            if(cur <= min_) min_ = cur;
    }while(next_permutation(sym.begin(), sym.end()));


     cout << max_ <<"\n" << min_;


   
    

}