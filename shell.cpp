#include <iostream>
#include <fstream>

using namespace std;

int a[105];
int b[105];
int g[105];
int swaps(int j, int n){
    int counter = 0;
    int start = j; //1
    for(int i = 0; i < n; i++){
        if(a[i] == start){
            start = b[i];
        }else if(b[i] == start){
            start = a[i];
        }
        if(g[i] == start){
            counter++;
        }
    }
    return counter;
}
int main(void){
    ifstream cin("shell.in");
    ofstream cout("shell.out");
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> g[i];
    }
    int max2 = -1;
    for(int i = 1; i <= 3; i++){
        max2 = max(max2, swaps(i, n));
    }
    cout << max2 << "\n";
    return 0;
}