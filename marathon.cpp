#include <fstream>

using namespace std;

const int MAXN = 100000;

int N;
int X[MAXN], Y[MAXN];

int dist(int a, int b) {
  return abs(X[a] - X[b]) + abs(Y[a] - Y[b]);
}

int main() {
    ifstream fin("marathon.in");
    fin >> N;
    int totalD = 0; // this is without removing any checkpoints
    for (int i = 0; i < N; i++) {
      fin >> X[i] >> Y[i];
      if (i > 0) {
        totalD += dist(i, i-1);
      }

    }

    int minD = totalD;
    // try removing each town
    for (int i = 1; i < N - 1; i++){
      int tmpD = totalD - dist(i-1, i) - dist(i, i+1) + dist(i-1, i+1);
      if (tmpD < minD) {
        minD = tmpD;
      }
    }

    ofstream fout("marathon.out");
    fout << minD << "\n";
    return 0;
}
