#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ifstream cin("crossroad.in");
    ofstream cout("crossroad.out");
    int n;
    cin >> n;
    int lastseen[11];
    int ans = 0;
    fill(lastseen, lastseen + 11, -1);
    for(int i = 0; i < n; i++){
        int cow, pos;
        cin >> cow >> pos;
        if(lastseen[cow - 1] != -1 && pos != lastseen[cow - 1]){
            ans++;
        }
        lastseen[cow - 1] = pos;
    }
    cout << ans << "\n";
    return 0;
}