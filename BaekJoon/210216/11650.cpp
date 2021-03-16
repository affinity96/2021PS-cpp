#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class  Num{
public:
    int x;
    int y;
    Num(int x_, int y_){
        this->x = x_;
        this->y = y_;
    }
    bool operator < (Num &num){
        if(this->x==num.x){
            return this->y < num.y;
        }else{
            return this->x < num.x;
        }
    }
};
int main(){
    int N; cin >> N;
    vector <Num> numbers;
    for(int n=0; n<N; n++){
        int x;
        int y;
        cin >> x >> y;
        numbers.push_back(Num(x, y));
    }
    sort(numbers.begin(), numbers.end());
    for(int n=0; n<N; n++){
        cout << numbers[n].x << " "<< numbers[n].y<<"\n";
    }
}