#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int dist(pair<int, int> x, pair<int, int> y){
    return (y.first - x.first) + (y.second - x.second);
}
int main(void){
    int n;
    cin >> n;
    pair<int, int> points[n];
    for(int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(dist(points[i], points[k]) < dist(points[i], points[j]))
            }
        }
    }
    return 0;
}