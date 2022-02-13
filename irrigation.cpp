#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int a, b, weight;
};
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
vector<Edge> v;
bool cmp(Edge a, Edge b){
    return a.weight < b.weight;
}
int kruskal(int n){
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    DSU dsu(n + 1);
    for(Edge e: v){
        if(!dsu.same_set(e.a, e.b)){
            dsu.unite(e.a, e.b);
            ans += e.weight;
        }
    }
    if(dsu.size(0) != n){
        return -1;
    }else{
        return ans;
    }
}

int main(void){
    ifstream cin("irrigation.in");
    ofstream cout("irrigation.out");
    int n, c;
    cin >> n >> c;
    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(((x[i]-x[j])*(x[i]-x[j])) + ((y[i]-y[j])*(y[i]-y[j])) >= c){
                Edge push;
                push.a = i;
                push.b = j;
                push.weight = (((x[i]-x[j])*(x[i]-x[j])) + ((y[i]-y[j])*(y[i]-y[j])));
                v.push_back(push);
            }
        }
    }
    long long ans = kruskal(n);
    cout << ans << "\n";
    return 0;
}