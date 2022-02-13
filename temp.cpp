#include <iostream>
#include <vector>
using namespace std;

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
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    for(int i = 0; i < q; i++){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            if(!dsu.same_set(a, b)){
                cout << 0 << "\n";
            }else{
                cout << 1 << "\n";
            }
        }else{
            dsu.unite(a, b);
        }
    }
    return 0;
}