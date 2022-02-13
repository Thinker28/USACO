#include <iostream>
#include <unordered_set>
#include <vector>
#include <fstream>
using namespace std;

bool visited[200000];
vector<int> adj[200000];
unordered_set<int> closed;
void dfs(int node){
    visited[node] = true;
    for(int v: adj[node]){
        if(!visited[v] && closed.count(v) == 0){
            dfs(v);
        }
    }
}
bool connected(int n){
    for(int i = 0; i < n; i++){
        if(!visited[i] && closed.count(i) == 0){
            return false;
        }
    }
    return true;
}
int main(void){
    ifstream cin("closing.in");
    ofstream cout("closing.out");
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int pos;
    int closing[n];
    for(int i = 0; i < n; i++){
        cin >> closing[i];
        closing[i]--;
    }
    for(int i = 0; i < n; i++){
        dfs(closing[n - 1]);
        if(connected(n)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        fill(visited, visited + 200000, false);
        closed.insert(closing[i]);
    }
    return 0;
}