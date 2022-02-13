#include <iostream>
#include <fstream>


using namespace std;

char arr[10][10];
ifstream fin("cowtip.in");
ofstream fout("cowtip.out");
int main(void){
    int n;
    fin >> n;
    for (int r = 0; r < n; r++){
        for (int c = 0; c < n; c++){
            fin >> arr[r][c];
        }
    }

    int numToggles = 0;

    for (int r = n-1; r >= 0; r--) {
        for (int c = n-1; c >= 0; c--) {
            if (arr[r][c] == '1') {
                numToggles++;
                for (int r1 = 0; r1 <= r; r1++) {
                    for (int c1 = 0; c1 <= c; c1++) {
                        if (arr[r1][c1] == '1') {
                            arr[r1][c1] = '0';
                        } else {
                            arr[r1][c1] = '1';
                        }
                    }
                }
            }
        }
    }


    fout << numToggles << "\n";
    return 0;
}
