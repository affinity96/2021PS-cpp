#include <iostream>
#include <vector>

using namespace std;

void preorder(vector<pair<char, char>>graph, char a){
    
    if(a == '.') return;
    else{
        cout << a;
        preorder(graph, graph[a-'A'].first);
        preorder(graph, graph[a-'A'].second);
    }
}
void inorder(vector<pair<char, char>>graph, char a){
    
    if(a == '.') return;
    else{
        inorder(graph, graph[a-'A'].first);
        cout << a;
        inorder(graph, graph[a-'A'].second);
    }
}
void postorder(vector<pair<char, char>>graph, char a){
    
    if(a == '.') return;
    else{
        postorder(graph, graph[a-'A'].first);
        postorder(graph, graph[a-'A'].second);
        cout << a;    
    }
}
int main(){
    cin.tie(0);
    int N; cin >> N;
    vector<pair<char, char>>graph(N);
    for(int n=0; n<N; n++){
        char a, b, c; cin >> a >> b>> c;
        graph[a-'A'].first = b;
        graph[a-'A'].second = c;

    }

    preorder(graph, 'A');
    cout << "\n";
    inorder(graph,'A');
    cout << "\n";
    postorder(graph,'A');
}