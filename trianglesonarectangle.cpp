#include <iostream>


using namespace std;

int main(void){
	long long int t;
	cin >> t;
	for(long long int i = 0; i < t; i++){
		long long int w, h;
		cin >> w >> h;
		long long int ans = -1;
		for(long long int line = 0; line < 4; line++){
			long long int k;
			cin >> k;
			long long int left, right;
			for(long long int j = 0; j < k; j++){
				long long int v;
				cin >> v;
				if(j == 0){
					left = v;
				}else{
					right = v;
				}
			}
			if(line == 0 || line == 1){
				ans = max(ans, (right - left) * h);
			}else{
				ans = max(ans, (right - left) * w);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}