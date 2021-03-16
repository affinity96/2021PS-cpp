#include <iostream>
#include <vector>

using namespace std;
int N;
int cnt=0;
vector<pair<int, int>>ans;
void hanoi(int n, int from, int to, int aux){
    if(n==1) {
        ans.push_back(make_pair(from, to));
        cnt ++;
        return;
    }else{
        hanoi(n-1, from, aux, to);
        ans.push_back(make_pair(from, to));
        cnt ++;
        hanoi(n-1, aux, to, from);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    hanoi(N, 1, 3, 2);

    cout << cnt << "\n";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i].first <<" "<<ans[i].second<<"\n";
    }
}