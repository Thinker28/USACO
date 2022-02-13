/*
ID: amogh.d1
TASK: hamming
LANG: C++ 
*/
#include <iostream>
#include <fstream>  
#include <bitset>
#include <vector>

using namespace std;

int hamming(int n1, int n2)
{
    int x = n1 ^ n2;
    int setBits = 0;
 
    while (x > 0) {
        setBits += x & 1;
        x >>= 1;
    }
 
    return setBits;
}
int main(void){
    ifstream cin("hamming.in");
    ofstream cout("hamming.out");
    int n, b, d;
    cin >> n >> b >> d;
    vector<int> ans;
    for(int i = 0; i < (1 << b); i++){
        bool bad = false;
        for(int x: ans){
            if(hamming(i, x) < d){
                bad = true;
            }
        }
        if(!bad){
            ans.push_back(i);
            if(ans.size() == n){
                break;
            }
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(((i+1)%10 == 0 && i != 0) || i == ans.size()-1){
            cout << "\n";
        }else{
            cout << " ";
        }
    }
    return 0;
}