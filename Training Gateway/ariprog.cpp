/*
ID: amogh.d1
TASK: ariprog
LANG: C++ 
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

bool bisquare[125001];
int main(void){
    ifstream cin("ariprog.in");
    ofstream cout("ariprog.out");
    int n, m;
    cin >> n >> m;
    for(int p = 0; p <= m; p++){
        for(int q = 0; q <= m; q++){
            bisquare[(p*p)+(q*q)] = true;
        }
    }
    vector<pair<int, int> > v;
    int m2 = 2*m*m;
    for(int a = 0; a <= m2; a++){
        for(int b = 1; b <= (m2-a)/((n-1)); b++){
            bool bad = false;
            for(int i = 0; i < n; i++){
                if(!bisquare[a+(i*b)]){
                    bad = true;
                    break; 
                }
            }
            if(!bad){
                v.push_back(make_pair(b, a));
            }
        }
    }
    if(v.size() == 0){
        cout << "NONE\n";
        return 0;
    }
    sort(v.begin(), v.end());
    for(auto p: v){
        cout << p.second << " " << p.first << "\n";
    }
    return 0;
}