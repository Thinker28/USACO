#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define f first
#define s second
bool visited[100000];
vector<pair<char, int> > adj[100000];
int color[100000];
bool contradict;
void dfs(int node, int color2){
    visited[node] = true;
    color[node] = color2;
    for(auto p: adj[node]){
        if((color[p.s] == 0 || color[p.s] == 1) && ((p.f == 'S' && color[p.s] != color[node]) || (p.f == 'D' && color[p.s] == color[node]))){
            contradict = true;
        }else{
            if(color[p.s] == -1 && p.f == 'S'){
                dfs(p.s, color[node]);
            }else if(color[p.s] == -1 && p.f == 'D'){
                dfs(p.s, color[node] ^ 1);
            }
        }
    }
}
int main(void){
    ifstream cin("revegetate.in");
    ofstream cout("revegetate.out");
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        char a;
        int b, c;
        cin >> a >> b >> c;
        --b, --c;
        adj[b].push_back(make_pair(a, c));
        adj[c].push_back(make_pair(a, b));
    }
    for(int i = 0; i < n; i++){
        color[i] = -1;
    }
    int comps = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            comps++;
            dfs(i, 1);
            if(contradict){
                cout << 0 << "\n";
                return 0;
            }
        }
    }
    cout << 1;
    for(int i = 0; i < comps; i++){
        cout << 0;
    }
    cout << "\n";
    return 0;
}