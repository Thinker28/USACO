#include <iostream>

using namespace std;

bool visited[105];
int t1[250];
int a[250];
int b[250];
int simulate(int pz, int t){
    int spreaded = 1;
    for(int i = 0; i < t; i++){
        if(a[i] == pz && !visited[b[i]]){
            visited[b[i]] = true;
            spreaded++;
        }
    }
    
}
int main(void){
    int n, T;
    cin >> n >> T;
    string s;
    cin >> s;
    int numInfected = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            numInfected++;
        }
    }
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(simulate(i, T) == numInfected){
            counter++;
        }
    }
    int minimum = numInfected - 1;
    




    return 0;
}