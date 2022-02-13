#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> adj[n];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    int cnt = adj[q.front()].size();
    int cnt2 = 0;
    int level = 0;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        int cnt = adj[q.front()].size();
        for(int v: adj[a]){
            visited[v] = true;
            q.push(v);
            qkfkdfk
        }
        cnt2++;
        if(cnt == cnt2){
            level++;
        }
    }
    return 0;
}