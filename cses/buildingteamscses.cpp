#include <iostream>
#include <vector>
using namespace std;

bool bad = false;
bool visited[100000];
int c[100000];
vector<int> adj[100000];
void dfs(int node, int color = 0){
    visited[node] = true;
    c[node] = color;
    for(int v: adj[node]){
        if(visited[v]){
            if(c[v] == c[node]){
                bad = true;
            }
        }
        if(!visited[v]){
            dfs(v, color ^ 1);
        }
    }
}
int main(void){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    if(bad){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        cout << c[i] + 1 << " ";
    }
    return 0;
}