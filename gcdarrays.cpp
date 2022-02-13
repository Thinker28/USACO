#include <iostream>

using namespace std;

int f(int l, int r){
	return (r - l + 1) - ((r / 2) - ((l - 1) / 2));

}
int main(void){
	int t;
	cin >> t;
	for(int test = 0; test < t; test++){
		int l, r, k;
		cin >> l >> r >> k;
		if(l == r && l > 1){
			cout << "YES\n";
			continue;
		}
		if(f(l, r) <= k){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
	return 0;
}