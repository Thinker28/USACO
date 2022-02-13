#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int n, x;
	cin >> n >> x;
	vector<int> l(n);
	for(int i = 0; i < n; i++){
		cin >> l[i];
	}
	int left = 0;
	int right = 0;
	int sum = 0;
	int ans = 1e9;
	while(left < n){
		while(right < n && sum + l[right] < x){
			sum += l[right];
			right++;
		}
		cout << sum << "\n";
		cout << right - left + 1 << "\n";
		ans = min(ans, right - left + 1);
		sum -= l[left];
		left++;
	}
	cout << ans << "\n";

	return 0;
}