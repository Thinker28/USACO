#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
  ifstream fin("outofplace.in");
  ofstream fout("outofplace.out");
  int n;
  int count = 0;
  fin >> n;
  int arr[n];
  int small;
  int temp;
  for(int i = 0; i < n; i++){
    fin >> arr[i];
  }
  for(int i = 0; i < n-1; i++){
    small = i;
    for(int j = i+1; j < n; j++)
    if(arr[j] < arr[small]){
      small = j;
    }
    temp = arr[i];
    arr[small] = arr[temp];
    count++;
  }
  fout << count << "\n";










  return 0;
}
