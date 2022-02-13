#include <iostream>
 
using namespace std;
#define ll long long
int main(void){
  ll n;
  cin >> n;
  ll ans = n / 5;
  for(int i = 25; n / i >= 1; i *= 5){
    ans += n / i;
  }
  cout << ans << "\n";
  return 0;
}