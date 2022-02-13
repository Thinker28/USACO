#include <iostream>
#include <fstream>

using namespace std;

int main(void){
  ifstream fin("paint.in");
  ofstream fout("paint.out");
  int x1, x2, b1, b2;
  fin >> x1 >> x2 >> b1 >> b2;
  //find the intreval
  int intreval = abs(x2 - x1) + abs(b2 - b1);
  //subtract by the amount of intersection
  intreval -= abs(max(0, min(x2, b2) - max(x1, b1)));
  fout << intreval;


  return 0;
}
