#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n;
bool visited[4000][4000];
bool grid[4000][4000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void){
	// ifstream cin("gates.in");
	// ofstream cout("gates.out");
	cin >> n;
	pair<int, int> cur = make_pair(1002, 1002);
	visited[cur.first][cur.second] = true;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		for(int j = 0; j < 2; j++){
			if(c == 'N'){
				cur.first++;
			}else if(c == 'S'){
				cur.first--;
			}else if(c == 'E'){
				cur.second--;
			}else{
				cur.second++;
			}
			grid[cur.first][cur.second] = true;	
		}
		
	}
	int ans = 0;
	for(int i = 0; i < 2000; i++){
		for(int j = 0; j < 2000; j++){
			if(grid[i][j]){
				continue;
			}
			
		}
	}
	cout << ans - 1 << "\n";
	return 0;
}