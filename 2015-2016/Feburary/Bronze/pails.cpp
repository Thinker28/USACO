#include <fstream>
using namespace std;

int main(void){
    ofstream fout("pails.out");
    ifstream fin("pails.in");
    
    int x, y, m;
    fin >> x >> y >> m;
    int maxMilk = -1;
    for (int cy = 0; cy <= m/y; cy++) {
        int cx = (m - cy * y) / x;
        int milk = cx * x + cy * y;
        maxMilk = max(maxMilk, milk);
    }

    fout << maxMilk << "\n";
    return 0;
}
