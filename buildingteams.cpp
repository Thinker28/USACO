#include <iostream>

using namespace std;

bool visited[10000];
vector<int> adj[10000];
void dfs(int node){
    visited[node] = true;
    for(int v: adj[node]){
        dfs(v);
    }
}
int main(void){

    return 0;
}