#include <iostream>
#include <vector>

using namespace std;
int N;
vector <vector<char>> stars;

void byul(int a, int b, int n){
    if(n==1) {
        stars[a][b] = '*';
        return;
    }else{
        int n_ = n/3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if((i==1) && (j==1)) continue;
                else{
                    byul(a+i*n_, b+j*n_, n_);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    stars.assign(N, vector<char>(N, ' '));
   
    byul(0, 0, N);

    for(int n=0; n<N; n++){
        for(int m=0; m<N; m++){
            cout << stars[n][m];
        }
        cout << "\n";
    }
}