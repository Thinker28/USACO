#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    // ifstream cin("buckets.in");
    // ofstream cout("buckets.out");
    char arr[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> arr[i][j];
        }
    }
    int x1, y1, x2, y2, x3, y3;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
           if(arr[i][j] == 'B'){
               x1 = i;
               y1 = j;
           }else if(arr[i][j] == 'L'){
               x2 = i;
               y2 = j;
           }else if(arr[i][j] == 'R'){
               x3 = i;
               y3 = j;
           }
        }
    }
    
    if(((x1 == x2 && x2 == x3) && ((y3 <= max(y1, y2)) && (y3 >=  min(y1, y2)))) || (y1 == y2 && y2 == y3) && ((x3 <= max(x1, x2)) && x3 >= min(x1, x2))){
        cout << ((abs(x2 - x1) - 1) + abs(y2 - y1)) + 2 << "\n";
    }else{
        cout << (abs(x2 - x1) - 1) + abs(y2 - y1) << "\n";
    }

    return 0;
}