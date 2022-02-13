#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int t;
	cin >> t;
	for(int test = 0; test < t; test++){
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		vector<pair<int, int> > p(n);
		for(int i = 0; i < n; i++){
			p[i] = make_pair(b[i], a[i]);
		}
		sort(p.begin(), p.end());
		vector<int> an;
		// int i = 0;
		// while(i < n){
		// 	if(p[i].first > k){
		// 		break;
		// 	}
		// 	an.push_back(p[i].second);
		// 	i++;
		// }
		// sort(an.begin(), an.end());
		cout << an[an.size() - 1] << "\n";
	}
	return 0;
}