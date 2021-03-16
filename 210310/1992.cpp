#include <iostream>
#include <vector>
#include <string>

using namespace std;
int N;
vector<string>movie;

bool possible(int a, int b, int size){
    char start = movie[a][b];
  
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(start != movie[a+i][b+j]) return false;
        }
    }
    return true;
}

void quad(int a, int b, int size){
    
    if(possible(a, b, size)){
       cout << movie[a][b];
       return;
    }else{
        size/=2;
        cout << "(";
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                quad(a+i*size, b+j*size, size);
            }
        }

        cout << ")";
        return;
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    movie.assign(N,"");
    for(int n=0; n<N; n++){
        cin >> movie[n];
    }
    quad(0,0,N);
}