#include <iostream>
#include <fstream>
using namespace std;

int main(void){
  ifstream fin("square.in");
  ofstream fout("square.out");
  int u[4];
  int l[4];

  fin >> l[0] >> l[1] >> u[0] >> u[1];
  fin >> l[2] >> l[3] >> u[2] >> u[3];

  int length = max(u[0], u[2]) - min(l[0], l[2]);
  int width = max(u[1], u[3]) - min(l[1], l[3]);

  int sqlength = max(length, width);
  fout << sqlength * sqlength << "\n";
  return 0;
}
