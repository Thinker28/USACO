#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

bool visited[50000000][2];
int main(void){
	ifstream cin("feast.in");
	ofstream cout("feast.out");
	int t, a, b;
	cin >> t >> a >> b;
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	int ans = -1;
	//(cur state, if drank water = 1, else 0)
	while(!q.empty()){
		pair<int, bool> front = q.front();
		ans = max(ans, front.first);
		q.pop();
		bool drank = front.second;
		if(front.first + a <= t && !visited[front.first + a][front.second]){
			visited[front.first + a][front.second] = true;
			q.push(make_pair(front.first + a, front.second));
		}
		if(front.first + b <= t && !visited[front.first + b][front.second]){
			visited[front.first + b][front.second] = true;
			q.push(make_pair(front.first + b, front.second));
		}
		if(!drank && !visited[front.first / 2][1]){
			visited[front.first / 2][1] = true;
			q.push(make_pair(front.first / 2, 1));
		}
	}
	cout << ans << "\n";
	return 0;
}