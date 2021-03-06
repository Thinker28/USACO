#include <iostream>
#include <vector>
using namespace std;
using ll = long long;


int main() {
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  ll n;
  cin >> n;
  vector<ll> X(n, 0);
  vector<ll> Y(n, 0);
  for(ll i=0; i<n; i++) {
    cin >> X[i] >> Y[i];
  }
  // i will be corner
  // j will be flat (same x-coordinate as i)
  // k will be same y-coordinate as i
  ll best = 0;
  for(ll i=0; i<n; i++) {
    for(ll j=0; j<n; j++) {
      for(ll k=0; k<n; k++) {
        if(Y[i]==Y[j] && X[i]==X[k]) {
          ll area = (X[j]-X[i]) * (Y[k]-Y[i]);
          if(area < 0){
              area *= -1;
          }
          best = max(area, best);
        }
      }
    }
  }
  cout << best << "\n";
}
