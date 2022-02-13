/*
ID: amogh.d1
TASK: transform
LANG: C++ 
*/
#include <iostream>
#include <fstream>
using namespace std;
int n;
char original[10][10];
char grid[10][10];
char copy2[10][10];
//clockwise rotation
void crot(void){
    char copy[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            copy[i][j] = original[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            original[j][n - i - 1] = copy[i][j]; 
        }
    }
}
void crot2(void){
    char copy3[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            copy3[i][j] = copy2[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            copy2[j][n - i - 1] = copy3[i][j]; 
        }
    }
}


void oddreflect(void){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 2; j++){
            swap(copy2[i][j], copy2[i][n - j - 1]);
        }
    }
}
void evenreflect(void){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 2; j++){
            swap(copy2[i][j], copy2[i][n - j - 1]);
        }
    }
}
bool works(void){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(original[i][j] == grid[i][j]){
                count++;
            }
        }
    }
    if(count == n * n){
        return true;
    }
    return false;
}
bool works2(void){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(copy2[i][j] == grid[i][j]){
                count++;
            }
        }
    }
    if(count == n * n){
        return true;
    }
    return false;
}
int main(void){
    ifstream cin("transform.in");
    ofstream cout("transform.out");
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> original[i][j];
            copy2[i][j] = original[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    bool works3 = false;
    if(works()){
        works3 = true;
    }
    crot();
    if(works()){
        cout << 1 << "\n";
        return 0;
    }
    crot();
    if(works()){
        cout << 2 << "\n";
        return 0;
    }
    crot();
    if(works()){
        cout << 3 << "\n";
        return 0;
    }
    if(n % 2 == 0){
        evenreflect();
        if(works2()){
            cout << 4 << "\n";
            return 0;
        }
        crot2();
        if(works2()){
            cout << 5 << "\n";
            return 0;
        }
        crot2();
        if(works2()){
            cout << 5 << "\n";
            return 0;
        }
        crot2();
        if(works2()){
            cout << 5 << "\n";
        }
    }else{
        oddreflect();
        if(works2()){
            cout << 4 << "\n";
            return 0;
        }
        crot2();
        if(works2()){
            cout << 5 << "\n";
            return 0;
        }
        crot2();
        if(works2()){
            cout << 5 << "\n";
            return 0;
        }
        crot2();
        if(works2()){
            cout << 5 << "\n";
            return 0;
        }

    }
    if(works3){
        cout << 6 << "\n";
        return 0;
    }
    cout << 7 << "\n";
    return 0;
}