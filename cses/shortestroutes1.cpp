#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<pair<int, int> > adj[100000];
vector<long long> dist(100000, 1e18);
void dijkstra(int src){
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    dist[src] = 0;
    pq.push(make_pair(0, src));
    while(pq.size()){
        long long cdist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        //not shortest distance(already got updated/lazy dijkstra)
        if(cdist != dist[node]){
            continue;
        }
        for(pair<int, int> p: adj[node]){
            if(cdist + p.second < dist[p.first]){
                dist[p.first] = cdist + p.second;
                pq.push(make_pair(dist[p.first], p.first));
            }
        }
    }
}
int main(void){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a - 1].push_back(make_pair(b - 1, cost));
    }   
    dijkstra(0);
    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    return 0;
}