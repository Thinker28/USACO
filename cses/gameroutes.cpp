#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[100001];
vector<int> backedge[100001];
int main(void){
	int n, m;
	cin >> n >> m;
	vector<int> dp(n + 1);
	vector<int> indegree(n + 1);
	for(int i = 0; i < m; i++){	
		int a, b;
		cin >> a >> b;
		indegree[b]++;
		edge[a].push_back(b);
		backedge[b].push_back(a);
	}
	dp[1] = 1;
	queue<int> q;
	for(int i = 0; i < n; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int v: edge[node]){
			indegree[v]--;
			if(indegree[v] == 0){
				q.push(v);	
			}
		}
		for(int e: backedge[node]){
			dp[node] = (dp[node] + dp[e]) % 1000000007;
		}
	}
	cout << dp[n] << "\n";
	return 0;
}