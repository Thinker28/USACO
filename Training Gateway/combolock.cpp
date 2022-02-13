/*
ID: amogh.d1
TASK: combo
LANG: C++ 
*/
#include <iostream>
#include <fstream>
using namespace std;

int combo1[3];
int mastercombo[3];
int n;
int f(int a, int b){
    return min(n - max(a, b) + min(a, b), max(a,b) - min(a, b)); 
}
bool works(int a, int b, int c){
    if(f(combo1[0], a) <= 2 && f(combo1[1], b) <= 2 && f(combo1[2], c) <= 2){
        return true;
    }
    if(f(mastercombo[0], a) <= 2 && f(mastercombo[1], b) <= 2 && f(mastercombo[2], c) <= 2){
        return true;
    }
    return false;
}
int main(void){
    ifstream cin("combo.in");
    ofstream cout("combo.out");
    cin >> n;
    cin >> combo1[0] >> combo1[1] >> combo1[2];
    cin >> mastercombo[0] >> mastercombo[1] >> mastercombo[2];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                // cout << i << " " << j << " " << k << "\n";
                if(works(i, j, k)){
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}