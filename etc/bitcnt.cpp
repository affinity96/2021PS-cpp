#include <iostream>

using namespace std;

int main(){
    unsigned char state = 0x35;

    int bit_count = 0;

    for(int i=0; i<8; i++){
        if(state&(1<<i)) bit_count ++;
        cout << (1<<i) << "\n";
    }

    cout << "bitcount : " << bit_count;
}