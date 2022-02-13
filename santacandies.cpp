#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int n;
	cin >> n;
	int i = 1;
	int sum = 0;
	vector<int> ans;
	while(sum < n){
		ans.push_back(i);
		sum += i;
		i++;
	}
	int extra = sum-n;
	if(extra > 0){
		cout << ans.size() - 1 << "\n";
	}else{
		cout << ans.size() << "\n";
	}
	for(auto v: ans){
		if(v == extra){
			continue;
		}
		cout << v << " ";
	}


	return 0;
}