#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void){
    ifstream cin("cowjog.in");
    ofstream cout("cowjog.out");
    int n;
    cin >> n;
    int numGroups = 0;
    int pos[n];
    int speed[n];
    int groups[n];
    for(int i = 0; i < n; i++){
        cin >> pos[i] >> speed[i];
    }
    fill(groups, groups + n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }else{
                if(pos[i] < pos[j] && speed[i] > speed[j]){
                    groups[j] += groups[i];
                    groups[i] -= groups[i];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(groups[i] > 0){
            numGroups++;
        }
    }
    cout << numGroups << "\n";
    return 0;
}