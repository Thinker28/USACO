// #include <iostream>
// #include <vector>

// using namespace std;

// bool possible;
// vector<long long int> cur;
// bool done;

// void dfs(long long int a, long long int b){
// 	cur.push_back(a);
// 	if(a == b){
// 		if(possible){
// 			return;
// 		}
// 		cout << "YES\n";
// 		cout << cur.size() << "\n";
// 		for(int i: cur){
// 			cout << i << " ";
// 		}
// 		possible = true;
// 		return;
// 	}
	
// 	if((10 * a) + 1 <= b){
// 		dfs((10 * a) + 1, b);
// 	}
// 	if((a * 2) <= b){
// 		dfs(2 * a, b);
// 	}
// 	cur.pop_back();
// }
// int main(void){
// 	long long int a, b;
// 	cin >> a >> b;
// 	dfs(a, b);
// 	if(!possible){
// 		cout << "NO\n";
// 	}
// 	return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	long long int a, b;
	cin >> a >> b;
	vector<long long int> ans;
	ans.push_back(b);
	while(b > 0 && b > a){
		if(b % 2 == 0){
			b /= 2;
			ans.push_back(b);
			continue;
		}
		if(b % 10 == 1){
			b /= 10;
			ans.push_back(b);
			continue;
		}
		if(b % 10 != 1){
			break;
		}

	}
	reverse(ans.begin(), ans.end());
	if(b != a){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << ans.size() << "\n";
	for(auto v: ans){
		cout << v << " ";
	}
	return 0;
}