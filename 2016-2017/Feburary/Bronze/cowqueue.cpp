#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Cows{
    int arrive;
    int duration;
};

bool cmp(Cows a, Cows b){
    return a.arrive < b.arrive;
}

int main(void){
    ifstream cin("cowqueue.in");
    ofstream cout("cowqueue.out");
    int n;
    cin >> n;
    Cows arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].arrive;
        cin >> arr[i].duration;
    }
    sort(arr, arr + n, cmp);
    int curTime = 0;
    for(int i = 0; i < n; i++){
      if(curTime < arr[i].arrive){
          curTime = arr[i].arrive + arr[i].duration;
          
      }else{
          curTime += arr[i].duration;
      }  
    }
    cout << curTime;
    return 0;
}