#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ifstream cin("balancing.in");
    ofstream cout("balancing.out");
    int count[2][2];
    count[0][1] = 0;
    count[0][0] = 0;
    count[1][1] = 0;
    count[1][0] = 0;
    int n, b;
    cin >> n >> b;
    int cowsx[n];
    int cowsy[n];
    for(int i = 0; i < n; i++){
        cin >> cowsx[i] >> cowsy[i];
    }
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x = cowsx[i] - 1;
            int y = cowsy[j] - 1;
            for(int k = 0; k < n; k++){
                count[cowsx[k] < x][cowsy[k] < y]++;
            }
            int m = max(max(count[0][1], count[0][0]), max(count[1][1], count[1][0]));
                if(m < ans){
                    ans = m;
                }
                count[0][1] = 0;
                count[0][0] = 0;
                count[1][1] = 0;
                count[1][0] = 0;
        }
    }
    cout << ans;
    return 0;
}