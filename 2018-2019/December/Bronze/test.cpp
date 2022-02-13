#include <vector>
#include <iostream>

using namespace std;

int main(void){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.erase(a.begin() + 1);
	for(int v: a){
		cout << v << "\n";
	}
}
