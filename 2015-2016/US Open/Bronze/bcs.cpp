#include <iostream>
#include <fstream>
using namespace std;

char piece[10][8][8];
char figurine[8][8];
bool works = true;

int n;

char getpiece(int i, int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n){
        return '.';
    }else{
        return piece[i][x][y];
    }
}
int main(void){
    ifstream cin("bcs.in");
    ofstream cout("bcs.out");
    int k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> figurine[i][j];
        }
    }
    for(int d = 0; d < k; d++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> piece[d][i][j];
            }
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = i + 1; j < k; j++){
            for(int ix = -n - 1; ix <= n - 1; ix++){
                for(int iy = -n - 1; iy <= n - 1; iy++){
                    for(int jx = -n - 1; jx <= n - 1; jx++){
                        for(int jy = -n - 1; jy <= n - 1; jy++){
                            works = true;
                            for(int a = 0; a < n; a++){
                                for(int b = 0; b < n; b++){
                                    if(getpiece(i, a + ix, b + iy) == '#'
                                    && getpiece(j, a + jx, b + jy) == '#'){
                                        works = false;
                                        break;
                                        
                                    }
                                    char hastagatab = ((getpiece(i, a + ix, b + iy)
                                        == '#') || (getpiece(j, a + jx, b + jy) == '#'));
                                    if(hastagatab != (figurine[a][b] == '#')){
                                        works = false;
                                    }
                                    
                                }
                            }
                            if(works){
                                cout << i + 1 << " " << j + 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    

    
    return 0;
}