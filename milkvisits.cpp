#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

string breed;
vector<int> adj[100001];
bool visited[100001];
int comp[100001];
int num;
void dfs(int node){
	comp[node] = num;
	visited[node] = true;
	for(auto v: adj[node]){
		if(breed[node] == breed[v] && !visited[v]){
			dfs(v);
		}
	}
}
int main(void){
	ifstream cin("milkvisits.in");
	ofstream cout("milkvisits.out");
	num = 0;
	int n, m;
	cin >> n >> m;
	cin >> breed;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			num++;
			dfs(i);
		}
	}
	for(int i = 0; i < m; i++){
		int a, b;
		char c;
		cin >> a >> b >> c;
		if(breed[a - 1] == c || comp[a - 1] != comp[b - 1]){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	cout << "\n";

	return 0;
}