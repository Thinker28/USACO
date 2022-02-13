#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[200001];
int parent[200001];
pair<int, int> dp[200001];
void solve(int node, int depth){
	int x = node;
	int d = 0;
	while(d != depth && x != -1){
		if(dp[parent[x]].first + 1 <= depth && dp[parent[x]].first != 0){
			x = dp[parent[x]].second;
			d += dp[parent[x]].first + 1;
		}else{
			x = parent[x];
			d++;
		}
	}
	if(x == -1 && d != depth){
		cout << -1 << "\n";
	}else{
		dp[node].second = x;
		dp[node].first = depth;
		cout << x << "\n";
	}
}
int main(void){
	parent[1] = -1;	
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n - 1; i++){
        int boss; cin >> boss;
        parent[i + 2] = boss;
        adj[boss].push_back(i + 2);
    }
    for(int i = 0; i < q; i++){
    	int a, depth;
    	cin >> a >> depth;
    	solve(a, depth);
    }
	return 0;
}