#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define pb push_back
int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    queue<int> q;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].pb(b - 1);
        adj[b - 1].pb(a - 1);
    }
    int parent[n];
    parent[0] = -1;
    bool visited[n];
    fill(visited, visited + n, false);
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int d = q.front();
        q.pop();
        for(int v: adj[d]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                parent[v] = d;
            }
        }
    }
    int dest = n - 1;
    vector<int> path;
    if(!visited[dest]){
        cout << "IMPOSSIBLE\n";
    }else{
        int x = dest;
        while(x != -1){
            path.pb(x);
            x = parent[x];
        }
    }
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for(int i = 0; i < (int)path.size(); i++){
        cout << path[i] + 1 << " ";
    }


    return 0;
}