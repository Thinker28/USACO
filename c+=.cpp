#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int a, b, n;
		cin >> a >> b >> n;
		int moves = 0;
		while(true){
			if(b > a){
				a += b;
				if(a > n){
					break;
				}
			}else{
				b += a;
				if(b > n){
					break;
				}
			}
			moves++;
		}
		cout << moves+1 << "\n";
	}
	return 0;
}