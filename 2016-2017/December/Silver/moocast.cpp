#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> adj[205];
bool visited[205];
int p[205];
int distance(int x1, int x2, int y1, int y2){
    return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}
int cnt = 0;
void dfs(int node){
    visited[node] = true;
    for(int v: adj[node]){
        if(!visited[v]){
            cnt++;
            dfs(v);
        }
    }
}
int main(void){
    ifstream cin("moocast.in");
    ofstream cout("moocast.out");
    int n;
    cin >> n;
    int x[n];
    int y[n];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> x[i] >> y[i] >> p[i];
        x[i]--;
        y[i]--;
    }
    int connections = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(distance(x[i], x[j], y[i], y[j]) < p[i] && i != j){
                adj[i].push_back(j);
                connections++;
            }
        }
    }
    int maxCounter = 0;
    for(int i = 0; i < n; i++){
        dfs(i);
        maxCounter = max(maxCounter, cnt);
        cnt = 0;
        fill(visited, visited + n, false);
    }

    cout << maxCounter + 1 << "\n";
    return 0;
}