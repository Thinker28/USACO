#include <iostream>

using namespace std;

int main(void){
	long long n;
	cin >> n;
	for(long long i = 1; i <= n; i++){
		long long allcombos = (i * i) * ((i * i) - 1) / 2;
		long long attacking = 4 * (i - 1) * (i - 2);
		long long ans = allcombos - attacking;
		cout << ans << "\n";
	}
	return 0;
}