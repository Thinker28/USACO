#include <fstream>
#include <vector>
using namespace std;

int main(void){
  ifstream fin("planting.in");
  ofstream fout("planting.out");

  int n;
  fin >> n;

  vector<vector<int> > edges(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    fin >> a >> b;
    edges[a-1].push_back(b-1);
    edges[b-1].push_back(a-1);
  }

  int maxDegree = 0;
  for (int i = 0; i < n; i++) {
    maxDegree = max(maxDegree, (int) edges[i].size());
  }

  fout << maxDegree + 1 << "\n";

  return 0;
}
