#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<pair<int, int> > l(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> l[i].first;
		l[i].second = i;
		sum += l[i].first;
	}
	int target = sum / (n / 2);
	sort(l.begin(), l.end());
	for(int i = 0; i < n / 2; i++){
		cout << l[i].second + 1 << " " << l[n - i - 1].second + 1 << "\n";
	}
	return 0;
}