#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int max2 = -1;
	int len = 1;
	for(int i = 1; i < n; i++){
		if(arr[i] > arr[i - 1]){
			len++;
		}else{
			max2 = max(max2, len);
			len = 1;
		}
	}
	max2 = max(max2, len);
	cout << max2 << "\n";
	return 0;
}