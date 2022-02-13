#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ifstream cin("gymnastics.in");
    ofstream cout("gymnastics.out");
    int n, k;
    cin >> k >> n;
    int adj[n + 1][n + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            adj[i][j] = 0;
        }
    }
    int arr[k][n];
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            for(int k2 = j + 1; k2 < n; k2++){
                adj[arr[i][j]][arr[i][k2]]++;
            }
        }
    }
    int count = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(adj[i][j] == k){
                count++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}