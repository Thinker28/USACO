#include <iostream>
#include <fstream>
using namespace std;

char arr[55][55];

int main(void){
  ifstream fin("crosswords.in");
  ofstream fout("crosswords.out");
    int n, m;
    int counter = 0;
    fin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fin >> arr[i][j];
        }
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(c< m + 2 && arr[r][c] == '.' && arr[r][c+1] =='.' && arr[r][c+2] =='.' &&
            (c==0 || arr[r][c-1]=='#')){
                counter++;
                arr[r][c] = 'T';
            }
            else if(r < n + 2 && arr[r][c]=='.' && arr[r+1][c]=='.' && arr[r+2][c]=='.' &&
                       (r==0 || arr[r-1][c]=='#')){
                counter++;
                arr[r][c] = 'T';
            }
        }
    }
    fout << counter  << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'T'){
                fout << i+1 << " " << j+1 << "\n";
            }
        }
    }
  }
