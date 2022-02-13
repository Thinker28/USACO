#include <iostream>
#include <set>

using namespace std;

int cities[100000];
int main(void){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> cities[i];
	}
	set<int> towers;
	for(int i = 0; i < m; i++){
		int tower;
		cin >> tower;
		towers.insert(tower);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int dist = 2e9;
		auto it = towers.lower_bound(cities[i]);
		if(it != towers.end()){
			dist = *it - cities[i];
		}
		if(it != towers.begin()){
			it--;
			dist = min(dist, cities[i] - *it);
		}
		ans = max(ans, dist);
	}
	cout << ans << "\n";
	return 0;
}