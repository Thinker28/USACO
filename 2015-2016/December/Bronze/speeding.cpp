#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ifstream cin("speeding.in");
    ofstream cout("speeding.out");
    int mile[100];
    int n, m;
    cin >> n >> m;
    int curStart = 0;
    for(int i = 0; i < n; i++){
        int length, speedlim;
        cin >> length >> speedlim;
        for(int j = curStart; j < curStart + length; j++){
            mile[j] = speedlim;
        }
        curStart += length;
    }
    int curStart2 = 0;
    int ans = 0;
    for(int i = 0; i < m; i++){
        int length, speedLim;
        cin >> length >> speedLim;
        for(int j = curStart2; j < curStart2 + length; j++){
            ans = max(speedLim - mile[j], ans);
        }
        curStart2 += length;
    }
    cout << ans;
    return 0;
}
// #include <iostream>
// #include <fstream>
// using namespace std;

// int main(){

//     ifstream fin("speeding.in");
//     ofstream fout("speeding.out");
    
//     int N,M;
//     fin>>N>>M;
//     int road[N][2];
//     int bessie[M][2];
//     for(int i=0; i<N; i++){
//         fin>>road[i][0];
//         fin>>road[i][1];
//     }
//     for(int i=0; i<M; i++){
//         fin>>bessie[i][0];
//         fin>>bessie[i][1];
//     }
//     int bessiecurrent=0, roadcurrent=0;
//     int bessielength=0, roadlength=0;
//     int ans = 0;
//     int maxover=0;

//     while(bessiecurrent!=M && roadcurrent!=N){
//         maxover=max(bessie[bessiecurrent][1]-road[roadcurrent][1], 0);
//         ans = max(ans, maxover);
//         if(roadlength+road[roadcurrent][0] <= bessielength){
//             roadlength+=road[roadcurrent][0];
//             roadcurrent++;
//         }else{
//             bessielength+=bessie[bessiecurrent][0];
//             bessiecurrent++;
//         }
//     }
//     fout<<maxover;
        
// }