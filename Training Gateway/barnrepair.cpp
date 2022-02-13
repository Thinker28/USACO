/*
ID: amogh.d1
TASK: barn1
LANG: C++ 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(void){
    ifstream cin("barn1.in");
    ofstream cout("barn1.out");
    int m, n, c;
    cin >> m >> n >> c;
    int stalls[c];
    for(int i = 0; i < c; i++){
        cin >> stalls[i];
    }
    sort(stalls, stalls + c);
    vector<int> diff;
    int numStalls = 1;
    for(int i = 0; i < c - 1; i++){
        if(stalls[i + 1] - stalls[i] - 1 > 0){
            diff.push_back(stalls[i + 1] - stalls[i] - 1);
            numStalls++;
        }
    }
    sort(diff.begin(), diff.end());
    int covered = c;
    while(numStalls > m){
        int a = diff[0];
        covered += a;
        diff.erase(diff.begin());
        numStalls--;
    }
    cout << covered << "\n";
    
    return 0;
}