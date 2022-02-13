#include <iostream>
#include <fstream>
using namespace std;



int main(void){
    ifstream cin("blist.in");
    ofstream cout("blist.out");
    int n;
    cin >> n;
    int start[n];
    int end[n];
    int lockers[n];
    int vacant[1000];
    for(int i = 0; i < 1000; i++){
        vacant[i] = 0;
    }

    for(int i = 0; i < n; i++){
        cin >> start[i] >> end[i] >> lockers[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = start[i]; j < end[i]; j++){
            vacant[j] += lockers[i];
        }
    }
    int maxVal = -1;
    for(int i = 0; i < 1000; i++){
        if(vacant[i] > maxVal){
            maxVal = vacant[i];
        }
    }
    cout << maxVal << "\n";
    
    
    return 0;
}