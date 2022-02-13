#include <iostream>
#include <vector>
#include <map>

using namespace std;

int p[48];
bool onpath[9][9];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dfs(int r, int c, int i){
	if((onpath[r][c - 1] && onpath[r][c + 1]) && (!onpath[r - 1][c] && !onpath[r + 1][c])){
		return 0;
	}
	if((!onpath[r][c - 1] && !onpath[r][c + 1]) && (onpath[r - 1][c] && onpath[r + 1][c])){
		return 0;
	}
	if(r == 7 && c == 1){
		if(i == 48){
			return 1;
		}else{
			return 0;
		}
	}
	if(i == 48){
		return 0;
	}
	onpath[r][c] = true;
	int ans = 0;
	if(p[i] < 4){
		int r2 = r + dx[p[i]];
		int c2 = c + dy[p[i]];
		if(!onpath[r2][c2]){
			ans += dfs(r2, c2, i + 1);
		}
	}else{
		for(int j = 0; j < 4; j++){
			if(onpath[r + dx[j]][c + dy[j]]){
				continue;
			}
			ans += dfs(r + dx[j], c + dy[j], i + 1);
		}
	}
	onpath[r][c] = false;
	return ans;
}
int main(void){
	string path;
	getline(cin, path);
	for(int i = 0; i < 48; i++){
		char c = path[i];
		if(c == 'U'){
			p[i] = 0;
		}else if(c == 'R'){
			p[i] = 1;
		}else if(c == 'D'){
			p[i] = 2;
		}else if(c == 'L'){
			p[i] = 3;
		}else{
			p[i] = 4;
		}
	}
	for(int i = 0; i < 9; i++){
		onpath[0][i] = true;
		onpath[8][i] = true;
		onpath[i][0] = true;
		onpath[i][8] = true;
	}
	for(int i = 1; i <= 7; i++){
		for(int j = 1; j <= 7; j++){
			onpath[i][j] = false;
		}
	}
	int ans = dfs(1, 1, 0);
	cout << ans << "\n";
	return 0;
}