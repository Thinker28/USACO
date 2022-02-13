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
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= x; j++){
			if(j - coins[i] >= 0){
				dp[j] += dp[j - coins[i]];
				dp[j] %= (int)1e9 + 7;
			}
		}
	}
	cout << dp[x] << "\n";
	return 0;
}