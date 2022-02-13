#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}
int main(void){
	int n, m;
	cin >> n >> m;
	vector<int> l(n);
	for(int i = 0; i < n; i++){
		cin >> l[i];
	}
	sort(l.begin(), l.end(), cmp);
	
	int sum = 0;
	int i = 0;
	while(sum < m){
		sum += l[i];
		i++;
	}
	cout << i << "\n";
	return 0;
}