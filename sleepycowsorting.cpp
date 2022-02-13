#include <iostream>
#include <fstream>
using namespace std;
 
int n;
#define I int
const int MAXN = 1000000;
I A[MAXN];
 
int main(void){
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");
	fin >> n;
	for(I i = 0;i < n;i++){
        fin >> A[i];
    }
	int ans = n - 1;
	for(I i = n - 2;i >= 0;i--)
	{
		if(A[i] < A[i+1]) ans = i;
		else
			break;
	}
	fout << ans << '\n';
	return 0;
}