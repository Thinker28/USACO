#include <iostream>

using namespace std;

#define ll long long

static bool arr[2000000][2000000];
int main(void){
    ll n;
    cin >> n;
    arr[100000][1000000] = true;
    ll x = 1e6, y = 1e6;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        char dir;
        int dist;
        cin >> dir >> dist;
        for(int i = 0; i < dist; i++){
            if(dir == 'U'){
                y++;
            }else if(dir == 'R'){
                x++;
            }else if(dir == 'D'){
                y--;
            }else{
                y++;
            }
            if(arr[x][y]){
                break;
            }else if(!arr[x][y]){
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}