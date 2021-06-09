#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int N;

void hanoi(int num, int from, int to, int others){
    if(num == 0) return;
    hanoi(num-1, from, others, to);
    cout << from << " " << to <<"\n";
    hanoi(num-1, others, to, from);

}

int main(){
    cin >> N;
    string a = to_string(pow(2, N));
    a = a.substr(0, a.find('.'));
    a[a.length()-1] -= 1;
    cout << a << "\n";

    if(N<=20){
       hanoi(N, 1, 3, 2);
    }
    return 0;
}