#include <iostream>
#include <fstream>
using namespace std;

#define ll long long
bool increase(ll maxs, ll curs, ll length, ll curLength){
    if(((curs * (curs + 1)) / 2) - (maxs * (maxs + 1) /  2) <= (length - curLength) - 1){
        return true;
    }
    return false;
}
int main(void){
    cin.tie(0)->sync_with_stdio;
    ifstream cin("race.in");
    ofstream cout("race.out");
    ll length, t;
    cin >> length >> t;
    while(t--){
        ll x;
        cin >> x;
        ll curLength = 0;
        ll curSpeed = 0;
        ll time = 0;
        while(curLength < length){
            if(increase(x, curSpeed + 1, length, curLength)){
                curSpeed++;
            }else if(!increase(x, curSpeed, length, curLength)){
                curSpeed--;
            }
            // cout << "curSpeed: " << curSpeed << "\n";
            curLength += curSpeed;
            time++;
        }
        cout << time << "\n";
    }
    return 0;
}
