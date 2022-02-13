#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		int ans = 0;
		for(int j = 2; j * j <= x; j++){
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}