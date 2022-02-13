#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int t;
	cin >> t;
	for(int test = 0; test < t; test++){
		int n, d;
		cin >> n >> d;
		vector<int> l(n);
		bool flag = false;
		for(int i = 0; i < n; i++){
			cin >> l[i];
			if(l[i] > d){
				flag = true;
			}
		}
		if(!flag){
			cout << "YES\n";
			continue;
		}
		sort(l.begin(), l.end());
		if(l[0] + l[1] <= d){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}

	}
	return 0;
}