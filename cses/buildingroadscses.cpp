#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100000];
bool visited[100000];


void dfs(int node){
    visited[node] = true;
    for(int v: adj[node]){
        if(!visited[v]){
            dfs(v);
        }
    }
}


int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            a.push_back(i);
            dfs(i);
        }
    }
    cout << a.size() - 1 << "\n";
    for(int i = 1; i <= (int) a.size(); i++){
        cout << 1 << " " << a[i] + 1 << "\n";
    }
    return 0;
}