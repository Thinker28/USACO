#include <iostream>
#include <fstream>
using namespace std;

#define ll long long
ll s[251];
pair<ll, ll> boots[251];
ll best;
ll n, b;
bool visited[251][251];
void dfs(ll curstep, ll curboot){
    visited[curstep][curboot] = true;
    if(curstep == n - 1){
        best = min(best, curboot);
        return;
    }
    if(curstep + 1 <= n-1){
       for(ll steps = 1; steps <= boots[curboot].second; steps++){
            if(curstep + steps <= n - 1 && boots[curboot].first >= s[curstep+steps] && !visited[curstep + steps][curboot]){
                dfs(curstep + steps, curboot);
            }
        } 
    }
    if(curboot + 1 < b){
        for(ll boot = curboot + 1; curboot < b; curboot++){
            if(boots[boot].first >= s[curstep] && !visited[curstep][boot]){
                dfs(curstep, boot);
            }
        }
    }
}
int main(void){
    ifstream cin("snowboots.in");
    ofstream cout("snowboots.out");
    best = 1e9;
    cin >> n >> b;
    for(ll i = 0; i < n; i++){
        cin >> s[i];
    }
    for(ll i = 0; i < b; i++){
        cin >> boots[i].first >> boots[i].second;
    }
    dfs(0, 0);
    cout << best << "\n";
    return 0;
}