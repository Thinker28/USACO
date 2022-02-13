#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ifstream cin("cowroute.in");
    ofstream cout("cowroute.out");
    int a, b, n;
    cin >> a >> b >> n;
    int minCost = 1e9;
    for(int i = 0; i < 2 * n; i++){
        int cost, numCities;
        cin >> cost >> numCities;
        bool found = false;
        for(int j = 0; j < numCities; j++){
            int a1;
            cin >> a1;
            if(a1 == a){
                found = true;
            }else if(a1 == b && found){
                minCost = min(minCost, cost);
            }            
        }
    }
    if(minCost == 1e9){
        cout << -1 << "\n";
        return 0;
    }else{
        cout << minCost << "\n";
    }
    return 0;
}