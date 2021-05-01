#include <iostream>
#include <vector>

using namespace std;

int main(){
    int blocks[5][2] = {{0,92}, {1,20},{2,11},{1,-81},{3,98}};
    vector<vector<int>> map(5, vector<int>(5, -101));
    for(int i=0; i<5; i++){
        map[i][blocks[i][0]] = blocks[i][1];
    }
    for(int i=0; i<4; i++){
        for(int h=0; h<=i; h++){


        for(int j=0; j<=i; j++){
            int top = map[i][j];
            int bot1 = map[i+1][j];
            int bot2 = map[i+1][j+1];

            if(bot1 == -101 && bot2 == -101) continue;
            else{
                if(bot1 == -101){
                    map[i+1][j] = top-bot2;
                }else if(bot2 == -101){
                    map[i+1][j+1] = top-bot1;
                }
            }

        }
    }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << map[i][j] << " ";

        }
        cout << " \n";
    }
}