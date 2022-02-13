#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[100005];
vector<int> backedge[100005];

int main(void){
	int n, m;
	cin >> n >> m;
	vector<int> indegree(n + 1);
	vector<int> dp(n + 1);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
		indegree[b]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto v: edge[node]){
			indegree[v]--;
			if(indegree[v] == 0){
				q.push(v);
			}
		}

	}

	return 0;
}