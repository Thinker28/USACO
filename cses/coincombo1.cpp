#include <iostream>

using namespace std;

int dp[1000001];
int main(void){
	int n, x;
	cin >> n >> x;
	int coins[n];
	for(int i = 0; i < n; i++){
		cin >> coins[i];
	}
	dp[0] = 1;
	for(int sum = 0; sum <= x; sum++){
		for(int i = 0; i < n; i++){
			if(sum - coins[i] >= 0){
				dp[sum] += dp[sum - coins[i]];
				dp[sum] %= (int)1e9+7;
			}
		}
	}
	cout << dp[x] << "\n";
	return 0;
}