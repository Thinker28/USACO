#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int cow[100000];
int n, m, c;
bool check(int deltat){
    int left = 0;
    int nbuses = 0;
    int filled = 0;
    for(int right = 0; right < n; right++){
        if(cow[right] - cow[left] <= deltat && filled < c){
            filled++;
        }else if(cow[right] - cow[left] > deltat){
            left = right;
            filled = 1;
            nbuses++;
        }
        if(filled == c){
            filled = 0;
            left = right + 1;
            nbuses++;
        }
    }
    if(filled > 0){
        nbuses++;
    }
    return nbuses <= m;
}

int main(void){
    ifstream cin("convention.in");
    ofstream cout("convention.out");
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++){
        cin >> cow[i];
    }
    sort(cow, cow + n);
    int low = 0;
    int high = 1e9;
    while(low < high){
        int maxtdif = (low + high) / 2;
        int buses = 0;
        int busescow = 0;
        int mincow = 0;
        if(check(maxtdif)){
            high = maxtdif;
        }else{
            low = maxtdif + 1;
        }
        
    }
    cout << low << "\n";
    return 0;
}