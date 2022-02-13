#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> l(n);
	for(int i = 0; i < n; i++){
		cin >> l[i];
	}
	sort(l.begin(), l.end());
	for(int i = 0; i < n - 2; i++){
		for(int j = i + 1; j < n - 1; j++){
			if(l[i] + l[j] > l[j + 1]){
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}