#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<pair<int, int> > adj[5001];
bool visited[5001];
#define ll long long
void dfs(int node, int k){
    visited[node] = true;
    for(pair<int, int> v: adj[node]){
        if(!visited[v.first] && v.second >= k){
            dfs(v.first, k);
        }
    }
}
int main(void){
    ifstream cin("mootube.in");
    ofstream cout("mootube.out");
    ll n, q;
    cin >> n >> q;
    for(ll i = 0; i < n - 1; i++){
        ll a, b, r;
        cin >> a >> b >> r;
        a--, b--;
        adj[a].push_back(make_pair(b, r));
        adj[b].push_back(make_pair(a, r));
    }
    while(q--){
        ll count = 0;
        ll a, b;
        cin >> a >> b;
        b--;
        dfs(b, a);
        for(ll i = 0; i < n; i++){
            if(visited[i]){
                count++;
            }
        }
        cout << count - 1 << "\n";
        fill(visited, visited + n, false);
    }
    return 0;
}