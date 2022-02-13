#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		int ans = 0;
		for(int j = 1; j * j <= x; j++){
			if(x % j == 0){
				ans += ((j * j == x) ? 1 : 2);
			}
		}
		cout << ans << "\n";

	}
	return 0;
}