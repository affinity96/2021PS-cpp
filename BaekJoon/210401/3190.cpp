#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int N, K, L; 
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
vector<vector<bool>>snake_v;
vector<vector<bool>>apple;
deque<pair<int, int>>snake_p;
vector<char>times(10001, 'A');
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    apple.assign(N+1, vector<bool>(N+1, false));
    snake_v.assign(N+1, vector<bool>(N+1, false));

    cin >> K;
    for(int k=0; k<K; k++){
        int elem_f, elem_s;
        cin >> elem_f >> elem_s;
        apple[elem_f][elem_s] = true;
    }

    cin >> L;
    for(int l=0; l<L; l++){
        int elem; char elem_c;
        cin >> elem >> elem_c;
        times[elem] = elem_c;
    }


    int cur_i=1, cur_j=1;
    snake_p.push_back(make_pair(cur_i, cur_j));
    snake_v[cur_i][cur_j] = true;
    int cur_index = 1;
    int ans = 0;
    while(1){
      
        if(times[ans]!='A'){

            if(times[ans] == 'L'){
                cur_index = (cur_index+1)%4;
            }else{
                cur_index = (cur_index+3)%4;
            }
        }
        int dir_i = di[cur_index], dir_j = dj[cur_index];
        
        int temp_i = cur_i + dir_i;
        int temp_j = cur_j + dir_j;

        ans++;
        if(temp_i <= 0 || temp_j <=0 || temp_i > N || temp_j > N) break;
        else if(snake_v[temp_i][temp_j]) break;
        else if(apple[temp_i][temp_j]){
            snake_p.push_back(make_pair(temp_i, temp_j));
            snake_v[temp_i][temp_j] = true;
            apple[temp_i][temp_j] = false;
        }else{
            snake_p.push_back(make_pair(temp_i, temp_j));
            snake_v[snake_p.front().first][snake_p.front().second] = false;
            snake_v[temp_i][temp_j] = true;
            snake_p.pop_front();
        }
        cur_i = temp_i;
        cur_j = temp_j;


    }
    

cout << ans;

}