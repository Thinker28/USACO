#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n, x;
	cin >> n >> x;
	
	vector<pair<int, int> > v;
	for(int i = 0; i < n; i++){
		int e;
		cin >> e;
		v.push_back(make_pair(e, i));
	}
	sort(v.begin(), v.end());
	int l = 0;
	int r = n - 1;
	for(int i = 0; i < n; i++){
		int l = 0;
		int r = n - 1;
		while(l != r){
			int target = x - v[i].first;
			if(l != i && r != i && v[l].first + v[r].first == target){
				cout << v[l].second + 1 << " " << v[r].second + 1 << " " << v[i].second + 1 << "\n";
				return 0;
			}else if(v[l].first + v[r].first > target){
				r--;
			}else{
				l++;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}