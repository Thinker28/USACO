#include <iostream>
#include <vector>

using namespace std;

bool visited[100000];
vector<int> adj[100000];
int parent[100000];
int ev, uv;
bool dfs(int node, int p){
    visited[node] = true;
    parent[node] = p;
    for(auto v: adj[node]){
        if(!visited[v]){
            if(dfs(v, node)){
                return true;
            }
        }else if(visited[v] && v != p){
            ev = v;
            uv = node;
            return true;
        }
    }
    return false;
}
int main(void){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    bool cycle = false;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfs(i, -1)){
                cycle = true;
                break;
            }
        }
    }
    if(!cycle){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int cur = uv;
    vector<int> ans;
    ans.push_back(uv);
    while(cur != ev){
        ans.push_back(parent[cur]);
        cur = parent[cur];
    }
    ans.push_back(uv);
    cout << ans.size() << "\n";
    for(auto v: ans){
        cout << v+1 << " ";
    }

    return 0;
}