#include <iostream>
#include <vector>

using namespace std;

bool visited[100000];
vector<int> adj[100000][2];

void dfs(int node, int x){
	visited[node] = true;
	for(auto v: adj[node][x]){
		if(!visited[v]){
			dfs(v, x);
		}
	}
}
int main(void){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a - 1][0].push_back(b - 1);
		adj[b - 1][1].push_back(a - 1);
	}
	dfs(0, 0);
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			cout << "NO\n" << 1 << " " << i+1 << "\n";
			return 0;
		}
		visited[i] = false;
	}
	dfs(0, 1);
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			cout << "NO\n" << i+1 << " " << 1 << "\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}