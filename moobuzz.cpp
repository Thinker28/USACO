#include <iostream>

using namespace std;

int main(void){
	int j;
	cin >> j;
	int low = 0;
	int high = 1e9;
	while(low <= high){
		int mid = (low+high)/2;
		int n = mid/3;
		int k = mid/5;
		if(n+k > j){
			high = mid-1;
		}else{
			low = mid + 1;
		}
	}
	cout << high << "\n";
	return 0;
}