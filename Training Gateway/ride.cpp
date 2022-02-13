/*
ID: amogh.d1
LANG: C++
TASK: ride
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void){
  ifstream fin("ride.in");
  ofstream fout("ride.out");

  string comet, group;
  int b;
  int comet_multi = 1;
  int group_multi = 1;

  fin >> comet >> group;
  for (int i = 0; i < comet.length(); i++){
    char a = comet[i];
    b = int(a) - 64;
    // cout << "letter: " << a << ", associated number: " << b << "\n";
    comet_multi *= b;
  }

  for (int i = 0; i < group.length(); i++){
    char a = group[i];
    b = int(a) - 64;
    group_multi *= b;
  }



  if (comet_multi%47 == group_multi%47) {
    fout << "GO\n";

  }else{
    fout << "STAY\n";
  }



  return 0;
}
