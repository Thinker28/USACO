//(teamtictactoe)

#include <iostream>

using namespace std;

char arr[3][3];
bool diagonal(char ch){
    if(arr[0][0] == ch && arr[1][1] == ch && arr[2][2] == ch) return true;
    else if(arr[0][2] == ch && arr[1][1] == ch && arr[3][0] == ch) return true;
    else
        return false;
}
int main(void){
    char arr[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    if(diagonal(arr[0][0]) )){

    }
    for(int)
    return 0;
}