#include <iostream>
#include <vector>
using namespace std;

vector<int> h;
int operation(int numoperations, int i){
	h[i] -= numoperations;
	h[i + 1] -= numoperations;
	return numoperations * 2;
}
int solve(int n){
	h = vector<int> (n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	int ans = 0;
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = 1; i < n; i++){
			if(h[i] > h[i - 1]){
				flag = true;
				if(i == n - 1){
					return -1;
				}
				ans += operation(h[i] - h[i - 1], i);
			}else{
				flag = true;
				if(i == 1){
					return -1;
				}
				ans += operation(h[i - 1] - h[i], i - 2);
			}
		}
	}
	return ans;
}
int main(void){
	int testcases;
	cin >> testcases;
	for(int test = 0; test < testcases; test++){
		int n;
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}