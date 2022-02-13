// #include <iostream>
// #include <fstream>
// using namespace std;

// int main(void){
//     ifstream fin("mowing.in");
//     ofstream fout("mowing.out");
//     int n;
//     int field[2000][2000];
//     for(int i = 0; i < 2000; i++){
//         for(int j = 0; j < 2000; j++){
//             field[i][j] = -1;
//         }
//     }
//     field[1000][1000] = 0;
//     int t = 0;
//     fin >> n;
//     int x = 1000, y = 1000, ans = 1000;
//     int timeElapsed;
//     for(int i = 0; i < n; i++){
//         char dir;
//         int dist;
//         fin >> dir >> dist;
//             for(int j = 0; j < dist; j++){
//                 if(dir == 'N'){
//                     y++;
//                 }else if(dir == 'S'){
//                     y--;
//                 }else if(dir == 'E'){
//                     x++;
//                 }else{
//                     x--;
//                 }
//                 t++;
//                 if(field[x][y] == -1){
//                     field[x][y] = t;
//                 }else{
//                     timeElapsed = t - field[x][y];
//                     field[x][y] = t;
//                     ans = min(timeElapsed, ans);
//             }
//         }
//     }
//     if(ans == 1000){
//         fout << -1;
//     }else{
//         fout << ans;
//     }
//     return 0;
// }
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int field[2005][2005];

int main(){
    ifstream fin("mowing.in");
    ofstream fout("mowing.out");
    int difference = 1e9;
    int N;
    fin>>N;
    char direction[N];
    int steps[N]; 
    for(int i=0; i<N; ++i){
        fin>>direction[i]>>steps[i];
    }
    int x=1000, y=1000;
    int t=0;

    for(int i=0; i<N; ++i){
        if(direction[i]=='N'){
            for(int j=1; j<=steps[i];++j){
                ++y;
                ++t;
                if(field[x][y]!=0){
                    difference = min(difference, t-field[x][y]);
                }else{
                    field[x][y]=t;
                }
            }
        }
        else if(direction[i]=='S'){
            for(int j=1; j<=steps[i];++j){
                --y;
                ++t;
                if(field[x][y]!=0){
                    difference = min(difference, t-field[x][y]);
                }else{
                    field[x][y]=t;
                }
            }
        }
        else if(direction[i]=='E'){
            for(int j=1; j<=steps[i];++j){
                ++x;
                ++t;
                if(field[x][y]!=0){
                    ++t;
                    difference = min(difference, t-field[x][y]);
                }else{
                    ++t;
                    field[x][y]=t;
                }

            }
        }
        else{
            for(int j=1; j<=steps[i];++j){
                --x;
                ++t;
                    difference = min(difference, t-field[x][y]);
                }else{
                    field[x][y]=t;
                }
            }
        }

    }
    

    int answer;
    if(difference == 1e9){
        answer=-1;
    }else{
        answer = difference;
    }
    fout<<answer;
    return 0;
}