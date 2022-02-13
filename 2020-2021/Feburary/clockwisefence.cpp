#include <iostream>

using namespace std;

int clockwise(char a, char b){
    if(a == 'N' && b == 'E'){
        return 1;
    }else if(a == 'E' && b == 'S'){
        return 1;
    }else if(a == 'S' && b == 'W'){
        return 1;
    }else if(a == 'W' && b == 'N'){
        return 1;
    }else if(a == b){
        return -1;
    }else{
        return 0;
    }
}
int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int cw = 0, ccw = 0;
        for(int j = 0; j < s.length() - 1; j++){
            if(clockwise(s[j], s[j + 1]) == 1 ){
                cw++;
            }else if(clockwise(s[j], s[j + 1]) == 0){
                ccw++;
            }
        }
        if(cw > ccw){
            cout << "CW\n";
        }else{
            cout << "CCW\n";
        }
    }
    return 0;
}