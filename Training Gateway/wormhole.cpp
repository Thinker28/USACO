/*
ID: amogh.d1
TASK: wormhole
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> x, y, nextright, partner;
int n;
bool cycle(){
    for(int start = 1; start <= n; start++){
        int pos = start;
        for(int count = 0; count < n; count++){
            pos = nextright[partner[pos]];
        }
        if(pos != 0){
            return true;
        }
    }
    return false;
}
int solve(){
    int i;
    int ans = 0;
    for(i = 1; i <= n; i++){
        if(partner[i] == 0){
            break;
        }
    }
    if(i > n){
        if(cycle()){
            return 1;
        }
        return 0;
    }

    for(int j = i + 1; j <= n; j++){
        if(partner[j] == 0){
            partner[i] = j;
            partner[j] = i;
            ans += solve();
            partner[i] = partner[j] = 0;
        }
    }
    return ans;

}
int main(void){
    ifstream cin("wormhole.in");
    ofstream cout("wormhole.out");    
    cin >> n;
    x = y = nextright = partner = vector<int> (13);
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i]; 
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(x[j] > x[i] && y[i] == y[j] && (nextright[i] == 0 || x[j] - x[i] < x[nextright[i]] - x[i])){
                nextright[i] = j;
            }
        }
    } 

    int ans = solve();
    cout << ans << "\n";
    return 0;
}