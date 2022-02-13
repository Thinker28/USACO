#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void){
	long long n, k;
	cin >> n >> k;
	map<long long, long long> freq;
	vector<long long> l(n);
	for(long long i = 0; i < n; i++){
		cin >> l[i];
	}
	long long left = 0;
	long long right = 0;
	long long distinct = 0;
	long long ans = 0;
	while(left < n){
		while(right < n && distinct + (freq[l[right]] == 0) <= k){
			freq[l[right]]++;
			distinct += (freq[l[right]] == 1);
			right++;
		}
		ans += right - left;
		distinct -= (freq[l[left]] == 1);
		freq[l[left]]--;
		left++;
	}
	cout << ans << "\n";
	return 0;
}