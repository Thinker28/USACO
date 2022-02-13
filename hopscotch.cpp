#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 15;
char hopscotch[MAXN][MAXN];
int main(void){
    ifstream fin("hopscotch.in");
    ofstream fout("hopscotch.out");
    int r, c;
    fin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            fin >> hopscotch[i][j];
        }
    }
    int counter = 0;
    for(int row = 0; row < r; row++){
        for(int col = 0; col < c; col++){
            if((hopscotch[r - 1][c - 1] == 'B' && hopscotch[0][0] == 'R') || (hopscotch[r - 1][c - 1] == 'R' && hopscotch[0][0] == 'B')){
                counter++;
            }
            if(hopscotch[row][col] == 'B' && row > 0 && col > 0){
                counter++;
            }
        }
    }
    fout << counter << "\n";
    return 0;
}
