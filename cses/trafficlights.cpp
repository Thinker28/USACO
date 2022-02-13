#include <iostream>
#include <set>
using namespace std;

int main(void){
	int x, n;
	cin >> x >> n;
	set<int> lights;
	multiset<int> dist;
	dist.insert(x);
	lights.insert(x);
	lights.insert(0);
	int q;
	for(int i = 0; i < n; i++){
		cin >> q;
		auto it1 = lights.upper_bound(q);
		auto it2 = it1;
		it2--;
		//cur addition is splitting the distance between closest left and closest right
		dist.erase(dist.find(*it1 - *it2));
		dist.insert(q - *it2);
		dist.insert(*it1 - q);
		lights.insert(q);
		auto ans = dist.rbegin();
		cout << *ans << " ";
	}
	return 0;
}