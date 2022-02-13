#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
const int MAXN = 200005;
vector<int> adj[MAXN];
bool visited[MAXN];
int num_sub[MAXN];
 
int dfs(int node){
    visited[node] = true;
    int count2 = 0;
    for(int v: adj[node]){
        if(!visited[v]){
            count2 += 1 + dfs(v);
        }
    }
    num_sub[node] = count2;
    return count2;
}
int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int boss; cin >> boss;
        adj[boss].push_back(i + 2);
    }
   
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << num_sub[i] << " ";
    }
    
    return 0;
}