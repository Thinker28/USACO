#include <iostream>

using namespace std;

int main(void){
	int n, x;
  cin >> n >> x;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int sum = 0;
  for(int i = 0; i < n; i++){
    if((i + 1) % 2 == 0){
      sum += a[i] - 1;
    }else{
      sum += a[i];
    }
  }
  if(sum > x){
    cout << "NO\n";
  }else{
    cout << "YES\n";
  }
}