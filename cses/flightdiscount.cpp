#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int> > adj[100000];
vector<vector<long long> > dist(100000, 1e18);
vector<long long> dist2(100000, 1e18);
void dijkstra(int src){
		 priority_queue<pair<long long, pair<int, bool> >, vector<pair<long long, pair<int, bool> > >, greater<pair<long long, pair<int, bool> > > > pq;
		 //if we got to the state by doing our discount
		 dist[src] = 0;
		 pq.push(make_pair(0, make_pair(src, false)));
		 while(pq.size()){
		 	long long cdist = pq.top().first;
		 	long long node = pq.top().second.first;
		 	bool discount = pq.top().second.second;
		 	for(auto v: adj[node]){
		 		if(cdist + v.second < dist[v.first]){
		 			dist[v.first] = cdist + v.second;
		 			pq.push(make_pair(dist[v.first], v.first));
		 		}
		 		if(!discount && cdist + (v.second/2) < dist2[v.first]){
		 			dist2[v.first]
		 		}
		 	}
		 }

}
int main(void){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		adj[a - 1].push_back(make_pair(b - 1, w));

	}
	dijkstra(0);
	cout << dist[n - 1] << "\n";
	return 0;
}