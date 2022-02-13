#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(void){
  ifstream cin("outofplace.in.txt");
  // ofstream cout("outofplace.out");
  int n;
  int count = 0;
  cin >> n;
  int unsolved[n];
  int solved[n];
  for(int i = 0; i < n; i++){
    cin >> unsolved[i];
  }
  for(int i = 0; i < n; i++){
    solved[i] = unsolved[i];
  }
  sort(solved, solved + n);
  for(int i = 0; i < n; i++){
    if(unsolved[i] != solved[i]){
      count++;
      unsolved[i] = solved[i];

    }
  }
  cout << count - 1;
  return 0;
}
