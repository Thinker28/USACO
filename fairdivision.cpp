#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int t;
  cin >> t;
  for(int te = 0; te < t; te++){
    int n;
    cin >> n;
    int sum = 0;
    int one = 0;
    int two = 0;
    for(int i = 0; i < n; i++){
      int v;
      cin >> v;
      if(v == 1){
        one++;
      }else{
        two++;
      }
    }
    if(sum % 2){
      cout << "NO\n";
    }else{
      int target = sum/2;
      if(target % 2){
        if(target/2 < two && one > 1){
          cout << "YES\n";
        }else if(target/2 < two && (target/2 - two) + 1 < one){
          cout << "YES\n";
        }else{
          cout << "NO\n";
        }
      }else{
        if(target / 2 < two){
          cout << "YES\n";
        }else if(target / 2 > two && (target/2 - two) > one/2){
          cout << "YES\n";
        }else{
          cout << "NO\n";
        }
      }
  }
}
  return 0;
}
