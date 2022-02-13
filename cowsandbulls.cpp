#include <iostream>

using namespace std;

char possible1[1000];
char possible2[1000];
int main(void){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int b[n];
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    if(a[0] != 0 || b[0] != 0){
        possible1[0] = 'B';
        possible2[0] = 'B';
        if(b[0] > 0 || b[1] != 1){
            possible1[1] = 'B';
            possible2[1] = 'B';
        }
    }else{
        if(a[1] == 1 && b[1] == 0){
            possible1[0] = 'C';
            possible1[1] = 'C';
            possible2[0] = 'B';
            possible2[1] = 'B';
        }else if(a[1] == 0 && b[1] == 1){
            possible1[1] = 'C';
            possible1[0] = 'B';
            possible2[1] = 'B';
            possible2[0] = 'C';
        }else if(a[1] == 1 && b[1] == 1){
            possible1[1] = 'B';
            possible1[0] = 'C';
            possible2[1] = 'B';
            possible2[0] = 'B';
        }
    }
    pair<int, int> possiblesum1 = make_pair(0,0);
    //cows, bulls
    pair<int, int> possiblesum2 = make_pair(0,0);
    for(int i = 0; i < 2; i++){
        if(possible1[i] == 'C'){
            possiblesum1.first++;
        }else if(possible1[i] == 'B'){
            possiblesum1.second++;
        }
        if(possible2[i] == 'C'){
            possiblesum2.first++;
        }else{
            possiblesum2.second++;
        }
    }
    
    for(int i = 2; i < n; i++){
        if(possiblesum1.first == a[i] && possiblesum1.second == b[i]){
            possible1[i] = 'C';
            possiblesum1.first++;
            
        }else{
            possible1[i] = 'B';
            possiblesum1.second++;
        }
        if(possiblesum2.first == a[i] && possiblesum2.second == b[i]){
            possible2[i] = 'C';
            possiblesum2.first++;
        }else{
            possiblesum2.second++;
            possible2[i] = 'B';
        }
    }
    int bulls1, bulls2, cows1, cows2;
    bulls1 = bulls2 = cows1 = cows2 = 0;
    for(int i = 0; i < n; i++){
        if(possible1[i] == 'C'){
            cows1++;
        }else{      z
            bulls1++;
        }
        if(possible2[i] == 'C'){
            cows2++;
        }else{
            bulls2++;
        }
    }
    if(bulls1+cows1 == n){
        for(int i = 0; i < n; i++){
            cout << possible1[i] << " ";
        }
        cout << "\n";
    }else{
      for(int i = 0; i < n; i++){
            cout << possible2[i] << " ";
        } 
        cout << "\n";
    }
    return 0;
}