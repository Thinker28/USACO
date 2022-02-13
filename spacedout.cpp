#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<vector<int> > grid(n, vector<int> (n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
		}
	}
	int rowSum = 0;
	int colSum = 0;
	for(int row = 0; row < n; row++){
		int even = 0;
		int odd = 0;
		for(int col = 0; col < n; col++){
			if(col % 2 == 0){
				even += grid[row][col];
			}else{
				odd += grid[row][col];
			}
		}
		rowSum += max(even, odd);
	}
	for(int col = 0; col < n; col++){
		int even = 0;
		int odd = 0;
		for(int row = 0; row < n; row++){
			if(row % 2 == 0){
				even += grid[row][col];
			}else{
				odd += grid[row][col];
			}
		}
		colSum += max(even, odd);

	}
	cout << max(colSum, rowSum) << "\n";
	return 0;
}