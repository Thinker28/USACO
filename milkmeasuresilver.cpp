#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
using namespace std;

struct Cows{
    int day;
    int id;
    int sign;
};
bool cmp(Cows &a, Cows &b){
    return a.day < b.day;
}
int main(void){
    ifstream cin("measurement.in");
    ofstream cout("measurement.out");
    int n, d;
    cin >> n >> d;
    Cows arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].day >> arr[i].id >> arr[i].sign;
    }
    int highest = d;
    int count[n];
    int ans = 0;
    fill(count, count + n, d);
    for(int i = 0; i < n; i++){
        Cows a = arr[i];
        if(count[a.id] + a.sign > highest){
            ans++;
        }
        count[a.id] += a.sign;
    }
    cout << ans << "\n";
    return 0;
}