#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> adj[200000];
bool active[200001];
struct DSU{
    vector<int> sz;
    vector<int> parent;
    DSU(int n){parent = vector<int>(n, -1); sz = vector<int>(n, 1);}
    int find(int x){
        return parent[x] < 0 ? x : parent[x] = find(parent[x]);
    }
    bool same_set(int a, int b){
        return find(a) == find(b);
    }
    int size(int x){
        return sz[find(x)];
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y){
            return false;
        }
        if(sz[x] < sz[y]){
            sz[y] += sz[x];
            parent[x] = y;
        }else{
            sz[x] += sz[y];
            parent[y] = x;
        }
        return true;
	}
    
};
int main(void){
    ifstream cin("closing.in");
    ofstream cout("closing.out");
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int queries[n];
    for(int i = 0; i < n; i++){
        cin >> queries[i];
    }
    reverse(queries, queries + n);
    vector<string> ans(n);
    for(int i = 0; i < n; i++){
        int query = queries[i];
        active[query] = true;
        for(auto edge: adj[query]){
            if(active[edge]){
                dsu.unite(edge, query);
            }
        }
        if(dsu.size(query) == i + 1){
            ans.push_back("YES\n");
        }else{
            ans.push_back("NO\n"); 
        }
    }
    reverse(ans.begin(), ans.end());        
    for(auto a: ans){
        cout << a;
    }
    return 0;
}