#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
int n;
vector<int> adj[10005];
bool visited[10005];
unordered_set<int> prices;
vector<int> price;
int price2 = 0;
void dfs(int node){
    price2 += price[node];
    visited[node] = true;
    for(int v: adj[node]){
        if(v == 3){
            prices.insert(price2 + price[v]);
            visited[v] = true;
            return;
            
        }
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(void){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
        price.push_back(c);
    }
    for(int i = 0; i < n; i++){
        dfs(i);
    }
    for(int v: prices){
        cout << v << "\n";
    }
    long long max = 9000000;
    for(int v: prices){
        if(v / 2 < max){
            max = v / 2;
        }
    }
    cout << max << "\n";
    return 0;
}