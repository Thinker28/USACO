#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 5005;
int hrs[MAXN];
int mins[MAXN];
int sec[MAXN];
int indices[MAXN];

bool cmp(int a, int b){
  if(hrs[a] < hrs[b]){
    return true;
  }else if(hrs[a] == hrs[b] && mins[a] < mins[b]){
    return true;
  }else if(hrs[a] == hrs[b] && mins[a] == mins[b] && sec[a] < sec[b]){
    return true;
  }else{
    return false;
  }
}

int main(void){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> hrs[i] >> mins[i] >> sec[i];
    indices[i] = i;
  }
  for(int i = 0; i < n; i++){
    cout << indices[i] << "\n";
  }
  sort(indices, indices + n, cmp);
  cout << "\n\n";
  for(int i = 0; i < n; i++){
    cout << indices[i] << "\n";
  }
  for(int i = 0; i < n; i++){
    cout << hrs[indices[i]] << " " << mins[indices[i]]
    << " " << sec[indices[i]] << "\n";
  }


}
