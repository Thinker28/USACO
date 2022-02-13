#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
vector<int> adj[200001];
bool paired[200001];

void dfs(int node, int parent){
	for(auto v: adj[node]){
		if(v != parent){
			dfs(v, node);
			if(!paired[v] && !paired[node]){
				paired[v] = paired[node] = true;
				ans++;
			}
		}
	}
}
int main(void){
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	dfs(0, -1);
	cout << ans << "\n";
	return 0;
}