#include <iostream>
#include <vector>

using namespace std;
int N;
vector <vector<int>> nums;
vector <int> ans(3,0);

bool same(int i, int j, int size){
    int basic = nums[i][j];
    for(int a=i; a<i+size; a++){
        for(int b=j; b<j+size; b++){
            if(basic != nums[a][b]) return false;
        }
    }

    return true;
}

void divide(int i, int j, int size){
    if(same(i, j, size)){
        ans[nums[i][j]] += 1;
    }else{
    
        size /= 3;
        
        for(int a=0; a<3; a++){
            for(int b=0; b<3; b++){
                divide(i+a*size, j+b*size, size);
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    nums.assign(N, vector<int>(N));
    for(int n=0; n<N; n++){
        for(int m=0; m<N; m++){
            int a; cin >> a;
            nums[n][m] = ++a;
    
        }

    }
    divide(0,0,N);
    for(int i=0; i<3; i++){
        cout << ans[i] << "\n";
    }
}