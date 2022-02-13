#include <iostream>

using namespace std;

int main(void){
  int n;
  int maxD = -1;
  int x[5001];
  int y[5001];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }
  for(int i = 0; i < n; i++){
    cin >> y[i];
  }


  for(int ref = 0; ref < n; ref++){
    for(int moving = ref; + 1 < n - 1; ref++){

      if((abs((x[moving] - x[ref]) + (y[moving] - y[ref])))
       * abs((x[moving] - x[ref]) + (y[moving] - y[ref])) > maxD){
         maxD = abs((x[moving] - x[ref]) + (y[moving] - y[ref]))
          * abs((x[moving] - x[ref]) + (y[moving] - y[ref]));
       }
    }
  }

  cout << maxD << "\n";
  return 0;
}
