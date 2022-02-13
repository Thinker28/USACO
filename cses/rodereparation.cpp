#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, pair<int, int> > > v;

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
int cnt;
long long kruskal(int n){
    long long ans = 0;
    sort(v.begin(), v.end());
    DSU dsu(n+1);
    for(auto p: v){
        if(!dsu.same_set(p.second.first, p.second.second)){
            dsu.unite(p.second.first, p.second.second);
            ans += p.first;
            cnt++;
        }
    }
    return ans;
}
int main(void){
    cnt = 0;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(c, make_pair(a, b)));
    }
    long long ans = kruskal(n);
    if(cnt == n - 1){
        cout << ans << "\n";
    }else{
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}