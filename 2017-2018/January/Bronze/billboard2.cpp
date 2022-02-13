#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ifstream cin("billboard.in");
    ofstream cout("billboard.out");
    int corners = 0;
    int x1, y1, x2, y2;
    int a1, b1, a2, b2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;
    int ulx, uly, lrx, lry;
    ulx = x1;
    uly = y2;
    lrx = x2;
    lry = y1;
    if(a1 < x1 && x1 < a2 &&  b1 < y1 && y1 < b2){
        corners++;
    }
    if(a1 < x2 && a2 > x2 && x2 > b1 && x2 < b2){
        corners++;
    } 
    if(uly < b2 && uly > b1 && ulx < a2 && ulx > a1){
        corners++;
    }
    if(lrx > a1 && lrx < a2 && lry > b1 && lry < b2){
        corners++;
    }
    


    if(corners == 0 || corners == 1){
        cout << (y2 - y1) * (x2 - x1);
    }else if(corners == 4){
        cout << 0;
    }else{
        cout << ((y2 - y1) * (x2 - x1)) - (min(x2, a2) - max(a1, x1)) * (min(y2, b2) - max(y1, b1));
    }
    return 0;
}