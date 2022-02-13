#include <iostream>

using namespace std;

int main(void){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
  int l, r;
  cin >> l >> r;
  if(l == r){
    cout << 0 << "\n";
    continue;
  }
   if((r / 2) >= l){
    if((r / 2) * 2 == r){
     cout << ((r - 1) % (r / 2)) << "\n";
    }else{
      cout << (int) (r / 2) << "\n";
      // cout << (r - 1) % (((int) (r / 2)));
    }
   }else if(l + (l / 2) <= r){
    if((r / 2) * 2 == l){
     cout << l % (l + (l / 2)) << "\n";
    }else{
      
      cout << l % (l + (((int)(l / 2))   ) - 1) << "\n";
    }
   }else{
      cout << 1 << "\n";
    }
  }
  return 0;
}