#include <iostream>

using namespace std;

void solve(int a, int b, int c){
	if(b + c == a || a + c == b || a + b == c){
		cout << "YES\n";
		return;
	}
	if(a == b && c % 2 == 0){
		cout << "YES\n";
		return;
	} 
	if(a == c && b % 2 == 0){
		cout << "YES\n";
		return;
	}
	if(b == c && a % 2 == 0){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}
int main(void){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int a, b, c;
		cin >> a >> b >> c;
		solve(a, b, c);
	}
	return 0;
}