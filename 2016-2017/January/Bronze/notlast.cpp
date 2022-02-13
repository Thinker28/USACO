#include <algorithm>
#include <fstream>
using namespace std;

int n;
string cows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", \
"Annabelle", "Maggie", "Henrietta"};
int milks[7] = {0, 0, 0, 0, 0, 0, 0};

const int unreachable = 10000005;

int main(void) {
  ifstream fin("notlast.in");
  fin >> n;
  for (int i = 0; i < n; i++) {
    string cow;
    int milk;
    fin >> cow >> milk;
    for (int j = 0; j < 7; j++) {
      if (cows[j] == cow) {
        milks[j] += milk;
        break;
      }
    }
  }

  // find the minimum value
  int minMilk = unreachable;
  for (int i = 0; i < 7; i++) {
    minMilk = min(milks[i], minMilk);
  }

  // replace min milk with maximum
  for (int i = 0; i < 7; i++) {
    if (milks[i] == minMilk) {
      milks[i] = unreachable;
    }
  }

  // find the second minimum milk value
  minMilk = milks[0];
  int minIdx = 0;
  int freq = 0;
  for (int i = 0; i < 7; i++) {
    if (minMilk > milks[i]) {
      minMilk = milks[i];
      minIdx = i;
      freq = 1;
    } else if (minMilk == milks[i]) {
      freq++;
    }
  }

  ofstream fout("notlast.out");
  if (minMilk == unreachable || freq > 1) {
    fout << "Tie\n";
  } else {
    fout << cows[minIdx] << "\n";
  }

  return 0;
}
