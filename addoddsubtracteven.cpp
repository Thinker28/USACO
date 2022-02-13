#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int a, b;
		cin >> a >> b;
		if(a == b){
			cout << 0 << "\n";
			continue;
		}
		if(a > b){
			if((a - b) % 2 == 0 || a - b == 0){
				cout << 1 << "\n";
			}else{
				cout << 2 << "\n";
			}
		}else{
			if((b - a) % 2 == 1 || b - a == 1){
				cout << 1 << "\n";
			}else{
				cout << 2 << "\n";
			}
		}
	}
	return 0;
}