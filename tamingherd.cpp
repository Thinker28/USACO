#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int day[n];
	for(int i = 0; i < n; i++){
		cin >> day[i];
	}
	int count = -1;
	int breakouts = 0;
	for(int i = n - 1; i >= 0; i--){
		if(count <= -1){
			count = day[i];
		}
		if(day[i] != count && count < 0){
			cout << -1 << "\n";
			return 0;
		}
		if(count == 0){
			breakouts++;
			day[0] = 0;
		}
		count--;
	}
	int max = 0;
	for(int i = 0; i < n; i++){
		if(day[i] == -1){
			max++;
		}
	}
	cout << breakouts + 1 << " " << breakouts+1+max << "\n";
	return 0;
}