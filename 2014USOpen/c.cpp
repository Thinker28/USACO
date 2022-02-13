#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int color1, color2;
int colora[500000];
vector<int> adj[500000];
bool impossible;
void dfs(int node, int color){
    colora[node] = color;
    if(color == 0){
        color1++;
    }else{
        color2++;
    }
    for(int v: adj[node]){
        if(colora[v] != -1 && colora[v] == colora[node]){
            impossible = true;
        }else{
            if(colora[v] == -1){
                dfs(v, color ^ 1);
            }
        }
    }
}

bool solve(int n){
    for(int i = 0; i < n; i++){
        if(colora[i] == -1){
            dfs(i, 0);
            if(impossible){
                return false;
            }
        }
    }
    return true;
}
int main(void){
    ifstream cin("decorate.in");
    ofstream cout("decorate.out");
    color1 = color2 = 0;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    for(int i = 0; i < n; i++){
        colora[i] = -1;
    }
    if(!solve(n)){
        cout << -1 << "\n";
        return 0;
    }
    if(adj[0].size() == 0){
        cout << max(color1, color2) + 1 << "\n";
        return 0;
    }
    cout << max(color1, color2) << "\n";
    return 0;
}