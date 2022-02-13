#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[200000];
int a1 = -1;
int st;
void dfs(int node, int parent, int depth){
	for(auto v: adj[node]){
		if(v != parent){
			dfs(v, node, depth + 1);
		}
	}	
	if(depth > a1){
		st = node;
		a1 = depth;
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
	dfs(0, -1, 0);
	a1 = 0;
	dfs(st, -1, 0);
	cout << a1 << "\n";
	return 0;
}