#include <iostream>

using namespace std;

struct Point{
	int x, y;
}
int main(void){
	int n, m;
	cin >> n >> m;
	int grid[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		Point p1, p2;
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		p1.x--, p1.y--, p2.x--, p2.y--;
		int vertical = 0;
		int max2 = -1;
		for(int row = min(p1.x, p2.x); row < max(p2.x, p2.y); i++){
			int col;
			if(p1.x < p2.x){
				col = p1.y;
			}else{
				col = p2.y;
			}
			max2 = max(max2, abs(grid[row][col] - grid[row + 1][col]));
		}
		for(int col = min(p1.y, p2.y); col < max(p1.y, p2.y); col++){
			int row;
			if(p1.x > p2.x){
				row = p1.x;
			}else{
				row = p2.x;
			}
			max2 = max(max2, abs(grid[row][col] - grid[row][col + 1]));
		}
			

	}
	return 0;
}