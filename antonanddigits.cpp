#include <iostream>

using namespace std;

int main(void){
	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;
	int ans = 0;
	while(k2 > 0 && k5 > 0 && k6 > 0){
		k2--;
		k5--;
		k6--;
		ans+=256;
	}
	while(k3 > 0 && k2 > 0){
		k3--;
		k2--;
		ans+=32;
	}
	cout << ans << "\n";
	return 0;
}