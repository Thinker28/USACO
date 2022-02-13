#include <iostream>
#include <vector>
using namespace std;

int x, y, z;
vector<pair<int, int> > adj[10000];  
vector<bool> visited;
vector<int> popularity;
void dfs(int node){
	visited[node] = true;
	x++;
	z += popularity[node];
	for(pair<int, int> v: adj[node]){
		if(!visited[v.first]){
			y = max(y, v.second);
			dfs(v.first);
		}
	}
}
int main(void){
	visited = vector<bool> (100000);
	popularity = vector<int> (100000);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> popularity[i];
	}
	for(int i = 0; i < m; i++){
		int a, b, di;
		cin >> a >> b >> di;
		adj[a - 1].push_back(make_pair(b - 1, di));
		adj[b - 1].push_back(make_pair(a - 1, di));
	}
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			dfs(i);
			ans = min(ans, x*y*z);
			cout << x << " " << y << " " << z << "\n"; 
			x = y = z = 0;
		}
	}
	cout << ans << "\n";
	return 0;
}