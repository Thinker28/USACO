#include <iostream>
#include <set>
using namespace std;

int main(void){
	int ans1 = 0;
	int ans2 = 0;
	char ans[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> ans[i][j];
		}
	}
	char guess[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> guess[i][j];
		}
	}
	multiset<char> temp1;
	multiset<char> temp2;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(ans[i][j] == guess[i][j]){
				ans1++;
			}else{
				temp1.insert(ans[i][j]);
				temp2.insert(guess[i][j]);
			}
		}
	}
	for(auto v: temp2){
		if(temp1.count(v) > 0){
			ans2++;
			temp1.erase(temp1.find(v));
		}
	}
	cout << ans1 << "\n" << ans2 << "\n";
	return 0;
}