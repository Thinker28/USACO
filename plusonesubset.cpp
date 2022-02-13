#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int t;
  cin >> t;
  for(int te = 0; te < t; te++){
    int n;
    cin >> n;
    vector<int> l(n);
    for(int i = 0; i < n; i++){
      cin >> l[i];
    }
    sort(l.begin(), l.end());
    int median;
    if(n % 2){
      median = (l[(n / 2)] + l[(n / 2) - 1]) / 2;
    }else{
      median = l[n / 2];
    }
    vector<int> d(n);
    for(int i = 0; i < n; i++){
        d[i] = median - l[i];
    }
    int first_nonzero = 0, ans = 0;
    
  }
  return 0;
}
