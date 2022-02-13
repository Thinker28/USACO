#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	long long n;
	cin >> n;
	long long arr[n];
	for(long long i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	long long sum = 0;
	for(long long i = 0; i < n; i++){
		if(sum + 1 < arr[i]){
			break;
		}
		sum += arr[i];
	}
	cout << sum + 1 << "\n";
	return 0;
}