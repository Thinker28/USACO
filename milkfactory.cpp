#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool visited[105];
vector<int> vec[105];
void dfs(int node){
	visited[node] = true;
	for(int v: vec[node]){
		if(!visited[v]){
			dfs(v);
		}
	}
}
int main(void){
	ifstream cin("factory.in");
	ofstream cout("factory.out");
	int n;
	cin >> n;
	int count[n];
	fill(count, count + n, 0);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		vec[a - 1].push_back(b - 1);

	}
	for(int i = 0; i < n; i++){
		fill(visited, visited + n, false);
		dfs(i);
		for(int j = 0; j < n; j++){
			if(visited[j]){
				count[j]++;
			}
		}

	}
	for(int i = 0; i < n; i++){
		if(count[i] == n){
			cout << i + 1 << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";

	return 0;
}