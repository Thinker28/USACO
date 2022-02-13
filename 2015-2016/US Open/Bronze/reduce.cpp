#include <iostream>
#include <fstream>
using namespace std;

int x[50000];
int y[50000];
int calcAreawithoutj(int j, int n){
    int minx = 40000, maxx = -1, maxy = -1, miny = 40000;
    for(int i = 0; i < n; i++){
        if(i == j){
            continue;
        }else{
            minx = min(x[i], minx);
            miny = min(y[i], miny);
            maxx = max(x[i], maxx);
            maxy = max(y[i], maxy);
        }
    }
    return (maxx - minx) * (maxy - miny);
}

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("reduce.in");
    ofstream cout("reduce.out");
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    int minx = 40000, idxminx;
    for(int i = 0; i < n; i++){
        if(x[i] < minx){
            minx = x[i];
            idxminx = i;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(x[i] == minx){
            cnt++;
        }
    }
    int d = calcAreawithoutj(-9, n);
    int area1 = d;
    if(cnt == 1){
        area1 = min(area1, calcAreawithoutj(idxminx, n));
        
    }
    cnt = 0;
    int maxx = -1, idxmaxx;
    for(int i = 0; i < n; i++){
        if(x[i] > maxx){
            maxx = x[i];
            idxmaxx = i;
        }
    }
    for(int i = 0; i < n; i++){
        if(x[i] == maxx){
            cnt++;
        }
    }
    int area2 = d;
    if(cnt == 1){
        area2 = min(area2, calcAreawithoutj(idxmaxx, n));
    }
    cnt = 0;
    int miny = 40000, idxminy;
    for(int i = 0; i < n; i++){
        if(y[i] < miny){
            miny = y[i];
            idxminy = i;
        }
    }
    for(int i = 0; i < n; i++){
        if(y[i] == miny){
            cnt++;
        }
    }
    int area3 = d;
    if(cnt == 1){
        area3 = min(area3, calcAreawithoutj(idxminy, n));
    }
    cnt = 0;
    int maxy = -1, idxmaxy;
    int area4 = d;
    for(int i = 0; i < n; i++){
        if(y[i] > maxy){
            maxy = y[i];
            idxmaxy = i;
        }
    }
    for(int i = 0; i < n; i++){
        if(y[i] == maxy){
            cnt++;
        }
    }
    if(cnt == 1){
        area4 = min(area4, calcAreawithoutj(idxmaxy, n));
    }
    cout << min(min(area1, area2), min(area3, area4));
    
    return 0;
}