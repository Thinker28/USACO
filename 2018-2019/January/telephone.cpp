#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int mat[50][50];
int breeds[500000];
vector<int> adj[500000];
int main(void){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> breeds[i];
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(mat[i][j] == 1){
                for(int j1 = 0; j1 < n; j1++){
                    if(j1 != i){
                        if(breeds[j1] == breeds[j]){
                            adj[i].push_back(j1);
                        }
                    }
                }
            }
        }
    }
    int parents[n];
    parents[0] = -1;
    bool visited[n];
    fill(visited, visited + n, false);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int v: adj[a]){
            if(!visited[v]){
                parents[v] = a;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    int x = n - 1;
    int steps = 0;
    if(!visited[x]){
        cout << -1 << "\n";
        return 0;
    }
    int dist = 0;
    vector<int> path;
    while(x != -1){
        path.push_back(x);
        x = parents[x];
    }
    int ans = 0;
    reverse(path.begin(), path.end());
    for(int i = 0; i < (int)path.size() - 1; i++){
        ans += abs(path[i] - path[i + 1]);
    }
    cout << ans << "\n";

    return 0;
}