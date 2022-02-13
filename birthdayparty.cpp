#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> adj[5000];
bool visited[5000];
void dfs(int node, int r){
    visited[node] = true;
    for(int v: adj[nodee]){
        if(!visited[v] && v != r){
            dfs(v, r);
        }
    }
}
bool check(int n, int r){
    for(int i = 0; i < n; i++){
        if(!visited[i] && i != r){
            return false;
        }
    }
    return true;
}
int main(void){
    for(int i = 0; i < 10; i++){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }
        unordered_set<int> s;
        for(int j = 0; j < b; j++){
            int a1, b1;
            cin >> a1 >> b1;
            s.insert(a1);
            s.insert(b1);
            adj[a1].push_back(b1);
        }
        bool bad = false;
        for(int removed: s){
            int b;
            for(int a: s){
                if(a != removed){
                    b = a;
                    break;
                }
            }
            dfs(b, removed);
            if(!check())
        }
    }
    return 0;
}