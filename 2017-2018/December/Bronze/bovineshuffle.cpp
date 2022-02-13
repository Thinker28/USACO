#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int n;
    fin >> n;
    int target[n];
    int id[n];
    int shuffle[4][n];
    for (int i = 0; i < n; i++) {
        fin >> target[i];
        target[i]--;
        shuffle[0][i] = i;
    }
   
    for (int i = 0; i < n; i++) {
        fin >> id[i];
        
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            shuffle[i + 1][target[j]] = shuffle[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (shuffle[3][j] == i) {
                fout << id[j] << "\n";
                break;
            }
        }
    }
    
    return 0;
}
