#include <iostream>
#include <vector>
using namespace std;

#define ll long long
bool visited[100005];
vector<ll> adj[100005];
ll dfs(ll node, ll parent){
    visited[node] = true;
    ll num = adj[node].size();
    if(parent == -1){
        num++;
    }
    ll days = 0;
    ll cows = 1;
    while(cows < num){
        cows *= 2;
        days++;
    }
    ll ans = days;
    for(ll v: adj[node]){
        if(!visited[v]){
            ans += dfs(v, node) + 1;
        }
    }
    return ans;
}
int main(void){
    cin.tie(0)->sync_with_stdio;
    ll n;
    cin >> n;
    for(ll i = 0; i < n - 1; i++){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfs(0, -1) << "\n";

    return 0;
}