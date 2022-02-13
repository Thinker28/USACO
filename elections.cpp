#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}
int main(void){
	int t;
	cin >> t;
	for(int te = 0; te < t; te++){
		vector<pair<int, int> > v(3);
		cin >> v[0].first >> v[1].first >> v[2].first;
		v[0].second = 0;
		v[1].second = 1;
		v[2].second = 2;
		sort(v.begin(), v.end()); 
		vector<pair<int, int> > ans;
		for(int i = 0; i < 3; i++){
			if(i == 0){
				ans.push_back(make_pair(v[i].second, v[3].first - v[0].first + 1));
			}else if(i == 1){
				ans.push_back(make_pair(v[i].second, v[3].first - v[1].first + 1));
			}else{
				if(v[3] == v[2]){
					ans.push_back(make_pair(v[i].second, 1));
				}else{
					ans.push_back(make_pair(v[i].second, 0));
				}
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i].first << " ";
		}
		cout << "\n";
	}
	return 0;
}