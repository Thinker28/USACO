#include <iostream>
#include <fstream>
using namespace std;


int main(void){
    ifstream cin("art.in");
    ofstream cout("art.out");
    int n;
    cin >> n;
    char arr[n][n];
    bool possible[10];
    for(int i = 0; i < 10; i++){
        possible[i] = true;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(char color = '1'; color <= '9'; color++){
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == color){
                    count++;
                }
            }
        }
        if(count == 0){
            possible[color - '0'] = false;
            continue;
        }
        int xl, xh, yl, yh;
        xl = yl = 10;
        xh = yh = -1;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(arr[x][y] == color){
                    xl = min(xl, x);
                    yl = min(yl, y);
                    xh = max(x, xh);
                    yh = max(y, yh);
                }
            }
        }
        for(int x = xl; x <= xh; x++){
            for(int y = yl; y <= yh; y++){
                if(arr[x][y] != color){
                    possible[arr[x][y] - '0'] = false;
                }
            }
        }
    }
    int counter = 0;
    for(int i = 1; i < 10; i++){
        if(possible[i]){
            counter++;
        }
    }
    cout << counter << "\n";
    return 0;
}