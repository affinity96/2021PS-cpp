#include <iostream>
#include <vector>

using namespace std;
int N, M, K, cur_i, cur_j;
vector<vector<int>>map;
vector<int>dice = {0, 0, 0, 0, 0, 0, 0};

bool can_go(int dir){
    if(dir == 1){
        if(cur_j == M-1) return false;
    }else if(dir==2){
        if(cur_j == 0) return false;
    }else if(dir == 3){
        if(cur_i == 0) return false;
    }else if(dir == 4){
        if(cur_i == N-1) return false;
    }

    return true;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> M >> cur_i >> cur_j >> K;
    map.assign(N, vector<int>(M));
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            cin >> map[n][m];
        }
    }

    for(int k=0; k<K; k++){
        int dir; cin >> dir;
        if(can_go(dir)){
            vector<int>temp;
            temp.resize(dice.size());
            copy(dice.begin(), dice.end(), temp.begin());

            if(dir == 1){
                cur_j ++;
                dice[1] = temp[4];
                dice[2] = temp[2];
                dice[3] = temp[1];
                dice[4] = temp[6];
                dice[5] = temp[5];
                dice[6] = temp[3];
            }else if(dir == 2){
                cur_j --;
                dice[1] = temp[3];
                dice[2] = temp[2];
                dice[3] = temp[6];
                dice[4] = temp[1];
                dice[5] = temp[5];
                dice[6] = temp[4];
            }else if(dir == 3){
                cur_i --;
                dice[1] = temp[5];
                dice[2] = temp[1];
                dice[3] = temp[3];
                dice[4] = temp[4];
                dice[5] = temp[6];
                dice[6] = temp[2];
            }else if(dir == 4){
                cur_i ++;
                dice[1] = temp[2];
                dice[2] = temp[6];
                dice[3] = temp[3];
                dice[4] = temp[4];
                dice[5] = temp[1];
                dice[6] = temp[5];
            }

            if(map[cur_i][cur_j]==0){
                map[cur_i][cur_j] = dice[6];
            }else{
                dice[6] = map[cur_i][cur_j];
                map[cur_i][cur_j]=0;
            }

            cout << dice[1] << "\n";


        }


    }

}