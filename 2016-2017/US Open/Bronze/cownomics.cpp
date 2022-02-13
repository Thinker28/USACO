#include <iostream>
#include <fstream>
using namespace std;

int getPos(char c) {
  int pos;
    switch(c) {
        case 'A':
            pos = 0;
            break;
        case 'C':
            pos = 1;
            break;
        case 'G':
            pos = 2;
            break;
        case 'T':
            pos = 3;
            break;
        default:
            pos = -1;
    }
    return pos;
}

int main(void){
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    int n, m;
    fin >> n >> m;
    char spot[n][m];
    char plain[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fin >> spot[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fin >> plain[i][j];
        }
    }
    
    int numSpots = 0;
    bool seenSpotty[4];
    bool seenPlain[4];
    // loop through each column
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < 4; i++) {
            seenSpotty[i] = seenPlain[i] = false;
        }

        for (int i = 0; i < n; i++) {
            seenPlain[getPos(plain[i][j])] = true;
        }
        
        for (int i = 0; i < n; i++) {
            seenSpotty[getPos(spot[i][j])] = true;
        }
        
        // check if column j distinguishes between spotty and plain
        bool dist = true;      
        for (int i = 0; i < 4; i++) {
            if (seenSpotty[i] == seenPlain[i] && seenPlain[i]) {
                dist = false;
                break;
            }
        }
        
        if (dist) {
            numSpots++;
        }
    }
    
    
    fout << numSpots << "\n";
    return 0;
}
