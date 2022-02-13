#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define ll long long
vector<int> adj[110001];
ll color1;
ll color2;
bool visited[110001];
void dfs(int node, int color){
    visited[node] = true;
    if(color == 0){
        color1++;
    }else{
        color2++;
    }

    for(int v: adj[node]){
        if(!visited[v]){
            dfs(v, color ^ 1);
        }
    }
}
int main(void){
    color1 = color2 = 0;
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0, 1);
    ll ans = color1*color2;
    cout << ans - (n) + 1 << "\n";
    //color the graph with two colors
}