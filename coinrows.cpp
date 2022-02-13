#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int m;
	cin >> m;
	vector<vector<int> > grid(2, vector<int> (m));
	vector<vector<int> > dp(2, vector<int> (m));
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	//find shortest path
	dp[0][0] = grid[i][j];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < m; j++){
			if(i && j){
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
				continue;
			}
			if(i){
				dp[i][j] = dp[i - 1][j] + grid[i][j];
			}
			if(j){
				dp[i][j] = dp[i][j - 1] + grid[i][j];
			}
		}
	}
	
	return 0;
}