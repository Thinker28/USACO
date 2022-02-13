#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct Edge{
    int x, y, weight;
};
vector<Edge> v;
vector<int> id;
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

bool cmp(Edge a, Edge b){
    return a.weight > b.weight;
}
int kruskal(int n){
    DSU dsu(n + 1);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            Edge push;
            push.x = i;
            push.y = j;
            push.weight = id[i] ^ id[j];
            v.push_back(push);
        }
    }
    long long ans = 0;
    int elim = 0;
    sort(v.begin(), v.end(), cmp);
    for(Edge a: v){
        if(!dsu.same_set(a.x, a.y)){
            dsu.unite(a.x, a.y);
            elim++;
            ans += a.weight;
            if(elim == n - 1){
                return ans;
            }
        }
    }
}
int main(void){
    ifstream cin("superbull.in");
    ofstream cout("superbull.out");
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        id.push_back(a);
    }
    DSU dsu(n + 1);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            Edge push;
            push.x = i;
            push.y = j;
            push.weight = id[i] ^ id[j];
            v.push_back(push);
        }
    }
    long long ans = 0;
    int elim = 0;
    sort(v.begin(), v.end(), cmp);
    for(Edge a: v){
        if(!dsu.same_set(a.x, a.y)){
            dsu.unite(a.x, a.y);
            elim++;
            ans += a.weight;
            if(elim == n - 1){
                cout << ans << "\n";
                return 0;
            }
        }
    }
    return 0;
}