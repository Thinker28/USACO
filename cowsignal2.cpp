#include <iostream>

using namespace std;

const int MAXN = 100;
char aout[MAXN][MAXN];
int main(void){
    int m, n, k;
    cin >> m;
    cin >> n;
    cin >> k;

    for (int row = 0; row < m; row++){
        for (int col = 0; col < n; col++){
            char c;
            cin >> c;
            for (int i = 0; i < k; i++){
                for (int j = 0; j < k; j++){
                  aout[k*row+i][k*col+j] = c;

                }
            }
        }
    }

    for (int i = 0; i < k * m; i++) {
        for (int j = 0; j < k * n; j++) {
            cout << aout[i][j];
        }
      cout << "\n";
    }
}
n