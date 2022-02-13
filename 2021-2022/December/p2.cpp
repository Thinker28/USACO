#include <iostream>
#include <vector>
using namespace std;

int sign(int a){
	if(a < 0){
		return -1;
	}else if(a > 0){
		return 1;
	}else{
		return 0;
	}
}
int main(void){
	int n;
	cin >> n;
	vector<int> t(n), p(n), d(n);	
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	for(int i = 0; i < n; i++){
		cin >> t[i];
		d[i] = t[i] - p[i];
	}
	int i = 0;
	int ans = 0;
	while(true){
		while(sign(d[i]) == 0 && i < n){
			i++;
		}
		if(i == n){
			break;
		}
		int tsign = sign(d[i]);
		int r = i;
		while(r + 1 < n && sign(d[r + 1]) == tsign){
			r++;
		}
		for(int j = i; j <= r; j++){
			if(tsign == 1){
				d[j]--;
			}else{
				d[j]++;
			}
		}
		ans++;
	}
	cout << ans << "\n";

	return 0;
}