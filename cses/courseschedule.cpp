#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[20000000];
vector<int> adj[2000000];
vector<int> top_sort;
void dfs(int node){
    visited[node] = true;
    for(int v: adj[node]){
        if(!visited[v]){
            dfs(v);
        }
    }
    top_sort.push_back(node);
}
int main(void){
    int n, m;
    cin >> n >> m;
    pair<int, int> queries[m];
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        queries[i] = make_pair(a, b);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    int index[n];
    for(int i = 0; i < n; i++){
        index[top_sort[i]] = i;
    }
    for(int i = 0; i < m; i++){
        if(index[queries[i].first] > index[queries[i].second]){
            cout << "IMPOSSIBLE\n";
            return 0;
        }   
    }
    for(int v: top_sort){
        cout << v + 1 << " ";
    }
    return 0;
}