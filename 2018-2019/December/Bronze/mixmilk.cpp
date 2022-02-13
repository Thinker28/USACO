#include <iostream>
#include <fstream>
using namespace std;

int main(void){
  int capacity[3];
  int buckets[3];

  ofstream fout("mixmilk.out");
  ifstream fin("mixmilk.in");

  for(int i = 0; i < 3; i++){
    fin >> capacity[i] >> buckets[i];
  }

  int curpos = 0;
  // pour bucket[curpos] into bucket[(curpos + 1) % 3]
  for (int i = 0; i < 100; i++){
    int nextpos = (curpos + 1) % 3;
    // capacity[nextpos] - buckets[nextpos] + buckets[nextpos] = capacity[nextpos]
    int amt = min(capacity[nextpos] - buckets[nextpos], buckets[curpos]);
    buckets[nextpos] += amt;
    buckets[curpos] -= amt;
    curpos = nextpos;
  }

  for (int i = 0; i < 3; i++) {
    fout << buckets[i] << "\n";
  }   

  return 0;
}
