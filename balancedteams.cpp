#include <iostream>
#include <vector>
using namespace std;


int team[4];
int cowteamskill[12];
int skill[12];
int ans = 1e9;
void dfs(int cow){
    if(cow == 12){
        int notfull;
        for(int i = 0; i < 4; i++){
            if(cowteam[i] < 3){
                notfull = i;
            }
        }
        cowteam[cow] = notfull;
        team[notfull]++;
        int sum[4];
        fill(sum, sum + 4, 0);
        for(int i = 0; i < 12; i++){
            sum[cowteam[i]] += skill[i];
        }
        int s = min(min(sum[0], sum[1]), min(sum[2], sum[3]));
        int S = max(max(sum[0], sum[1]), max(sum[2], sum[3]));
        ans = min(ans, S - s);
        team[notfull]--;
        return;

    }
    for(int i = 0; i < 4; i++){
        if(team[i] < 3){
            cowteam[cow] = i;
            team[i]++;
            dfs(cow + 1);
        }
        team[i]--;
    }
}
int main(void){
    for(int i = 0; i < 12; i++){
        cin >> skill[i];
    }
    dfs(0);
    cout << ans << "\n";
    return 0;
}