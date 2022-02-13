#include <iostream>
#include <vector>
#include <stack>



void dfs(int node){
    stack<int> dfs2;
    dfs2.push(node);
    while(!dfs2.empty()){
        if(adj[dfs2.top()].size() == 0){
            dfs2.pop();
        }else{
            for(int v: adj[dfs2.top()]){
                if(!visited[v]){s
                    visited[v] = true;
                    dfs2.push(v);
                }

            }
        }
    }
    for(int v: adj[dfs2.top()]){
        visited[v] = true;
        dfs2.push(v);
    }

}
int main(void){
    
    return 0;
}