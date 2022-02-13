#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long
vector<int> adj[1005];
bool visited[1005];
int distance(int x1, int x2, int y1, int y2){
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
int cnt = 0;
void dfs(int node){
    cnt++;
    visited[node] = true;
    for(int v : adj[node]){
        if(!visited[v]){
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
        cin >> x[i] >> y[i];
    }
    ll low = 0, high = 1e18;
    while(low <= high){
        ll mid = (low + high) / 2;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(distance(x[i], x[j], y[i], y[j]) <= mid){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        bool works = false;
        dfs(0);
        // cout << "cnt: " << cnt << "\n";
        // cout << "mid: " << mid << "\n";
        if(cnt == n){
            works = true;
        }

        fill(visited, visited + n, false);
        if(works){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
        cnt = 0;
        for(int i = 0; i < n; i++){
            adj[i].clear();
        }
    }

    cout << high + 1 << "\n";
    return 0;
}