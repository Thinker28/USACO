#include <iostream>
#include <fstream>

using namespace std;

int main(void){
  ifstream fin("paint.in");
  ofstream fout("paint.out");
  int a, b, c, d;
  fin >> a >> b >> c >> d;
  int z = abs(d - b);
  int y = abs(c - a);
  fout << z * y;


  return 0;
}
