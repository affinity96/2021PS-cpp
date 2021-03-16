#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>>star;
int N;

void make(int h, int i, int j){
    if(h == 3){
        star[i][j] = '*';
        star[i+1][j-1] = '*';
        star[i+1][j+1] = '*';
        star[i+2][j-2] = '*';
        star[i+2][j-1] = '*';
        star[i+2][j] = '*';
        star[i+2][j+1] = '*';
        star[i+2][j+2] = '*';
    }else{
        h/=2;
        make(h, i, j);
        make(h, i+h, j-h);
        make(h, i+h, j+h);
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    star.assign(3072, vector<char>(6144,' '));
    make(N, 0, N-1);

    for(int i=0; i<N; i++){
        for(int j=0; j<2*N; j++){
            cout << star[i][j];
        }
        cout << " ";
        cout << "\n";

    }
}