#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int inlst(vector<pair<int, int> > vv, pair<int, int> v) {
  for (int i = 0; i < vv.size(); i++) {
    if (vv[i] == v) {
        return i;
    }
  }
  return -1;
}

int main() {
  ifstream cin("mowing.in");
  ofstream cout("mowing.out");
  int n;
  char dir;
  int period;
  vector<char> directions;
  vector<int> periods;

  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> dir >> period;
    directions.push_back(dir);
    periods.push_back(period);
  }
  
  vector<pair<int, int> > coords;
  int answer = 1e9, x = 0, y = 0;
  pair<int, int> c;
  c.first = x;
  c.second = y;
  coords.push_back(c);
  int t = 0;
  for (int i = 0; i < directions.size(); ++i) {
    char d = directions[i];
    int p = periods[i];
    for (int j = 0; j < p; j++) {
        t++;
      if (d == 'N') {
        c.second++;
        int a = inlst(coords, c);
        if (a != -1) {
          answer = min(answer, abs(t - a));
          t = 0;
        }
      }
      
      if (d == 'E') {
        c.first++;
        int a = inlst(coords, c);
        if (a != -1) {
          answer = min(answer, abs(t - a));
          t = 0;
        }
      }
      
      if (d == 'S') {
        c.second--;
        int a = inlst(coords, c);
        if (a != -1) {
          answer = min(answer, abs(t - a));
          t = 0;
        }
      }
      
      if (d == 'W') {
        c.first--;
        int a = inlst(coords, c);
        if (a != -1) {
          answer = min(answer, abs(t - a));
          t = 0;
        }

      }
      coords.push_back(c);
    }
    
  }
  if(answer == 1e9){
    cout << -1 << "\n";
  }else{
      cout << answer + 3 << "\n";
  }
  return 0;  
}