#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
long long maxx = -1;
long long maxy = -1;
long long minx = 1e9;
long long miny = 1e9;
bool visited[100005];
vector<long long> adj[100005];
pair<long long, long long> x_y[100005];
void dfs(long long node){
    visited[node] = true;
    maxx = max(x_y[node].first, maxx);
    maxy = max(x_y[node].second, maxy);
    minx = min(x_y[node].first, minx);
    miny = min(x_y[node].second, miny);
    for(long long v: adj[node]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(void){
    ifstream cin("fenceplan.in");
    ofstream cout("fenceplan.out");
    long long n, m;
    cin >> n >> m;
    for(long long i = 0; i < n; i++){
        cin >> x_y[i].first >> x_y[i].second;
    }
    for(long long i = 0; i < m; i++){
        long long a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long long minPerim = 1e9;
    for(long long i = 0; i < n; i++){
        if(!visited[i]){
            maxx = -1;
            maxy = -1;
            minx = 1e9;
            miny = 1e9;
            dfs(i);
            minPerim = min((2 * (maxx - minx)) + (2 * (maxy -  miny)), minPerim);
        }
        
    }
    cout << minPerim << "\n";

    return 0;
}
