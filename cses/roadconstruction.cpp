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
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    int numComponents = n;
    int maxsize = -1;
    while(m--){
        int x, y;
        cin >> x >> y;
        if(!dsu.same_set(x, y)){
            dsu.unite(x, y);
            maxsize = max(maxsize, dsu.size(x));
            numComponents--;
        }
        cout << numComponents << " " << maxsize << "\n";
    }
    return 0;
}