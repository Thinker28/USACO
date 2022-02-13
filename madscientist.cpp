#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define ll long long

int main(void){
  ifstream cin("breedflip.in");
  ofstream cout("breedflip.out");
  ll n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  bool mismatched = false;
  ll ans = 0;
  for(ll i = 0; i < n; i++){
    if(a[i] != b[i]){
      if(!mismatched){
        ans++;
        mismatched = true;
      }
    }else{
      mismatched = false;
    }
  }
  cout << ans << "\n";
  return 0;
}
