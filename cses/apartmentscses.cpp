#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n, m, k;
	cin >> n >> m >> k;
	int a[n];
	int b[m];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);
	int i = 0;
	int j = 0;
	int ans = 0;
	while(i < n && j < m){
		if(abs(a[i] - b[j]) <= k){
			ans++;
			i++;
			j++;
		}else{
			if(a[i] - b[j] > k){
				j++;
			}else{
				i++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}