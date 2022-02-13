/*
ID: amogh.d1
TASK: skidesign
LANG: C++ 
*/
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(void){
    cin.tie(0)->sync_with_stdio;
    ifstream cin("skidesign.in");
    ofstream cout("skidesign.out");
    int n;
    cin >> n;
    int elevations[n];
    for(int i = 0; i < n; i++){
        cin >> elevations[i];
    }
    int minCost = 1e9;
    for(int height = 1; height <= 83; height++){
        int cost = 0;
        for(int i = 0; i < n; i++){
            if(elevations[i] < height){
                cost += pow(height - elevations[i], 2);
            }else if(elevations[i] > height + 17){
                cost += pow(elevations[i] - (height + 17), 2);
            }
        }
        minCost = min(minCost, cost);
    }
    cout << minCost << "\n";
    return 0;
}