#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    int grid[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < m; i++){
    	cout << "\n";
        int rowa, cola, rowb, colb;
        cin >> rowa >> cola >> rowb >> colb;
        rowa--, rowb--, cola--, colb--;
        int ans = 1e9;
        if(rowa == rowb || rowb == rowa){
            ans = 0;
            for(int j = min(cola, colb); j < max(cola, colb); j++){
            	if(grid[rowa][j] - grid[rowa][j + 1] <= 0){
            		continue;
            	}
                ans = max(ans, grid[rowa][j] - grid[rowa][j + 1]);               
            }
        }else if(cola == colb || colb == cola){
            ans = 0;
            for(int j = min(rowa, rowb); j < max(rowa, rowb); j++){
            	if(grid[j][colb] - grid[j + 1][colb] <= 0){
            		continue;
            	}
                ans = max(ans, grid[j][colb] - grid[j + 1][colb]);
            }
        }
        if((rowa < rowb && colb > cola) || (rowb < rowa && cola > colb)){
        	cout << "Hit [*break1]\n";
        	cout << "Processing~ ";
            int ans1, ans2;
            ans1 = ans2 = 0;
            for(int j = min(rowa, rowb); j < max(rowa, rowb); j++){
            	if(grid[j][max(cola, colb)] - grid[j + 1][max(cola, colb)] <= 0){
            		continue;
            	}
                ans1 = max(ans1, grid[j][max(cola, colb)] - grid[j + 1][max(cola, colb)]);
            }
            cout << "ANS1 - " << ans1 << " ANS2 - " << ans2 << "\n";
            for(int j = min(cola, colb); j < max(cola, colb); j++){
            	if(grid[min(rowa, rowb)][j] - grid[min(rowa, rowb)][j + 1] <= 0){
            		continue;
            	}
                ans2 = max(ans2, grid[min(rowa, rowb)][j] - grid[min(rowa, rowb)][j + 1]);
            }
            cout << "MAX(ANS1, ANS2)" << max(ans1, ans2) << "\n";
            ans = min(ans, min(ans1, ans2));
            ans1 = ans2 = 0;
            for(int j = min(rowa, rowb); j < max(rowa, rowb); j++){
            	if(grid[j][min(cola, colb)] - grid[j + 1][min(cola, colb)] <= 0){
            		continue;
            	}
                ans1 = max(ans1, grid[j][min(cola, colb)] - grid[j + 1][min(cola, colb)]);
            }
            cout << "ANS1 - " << ans1 << " ANS2 - " << ans2 << "\n";
            for(int j = min(cola, colb); j < max(cola, colb); j++){
            	if(grid[max(rowa, rowb)][j] - grid[max(rowa, rowb)][j + 1] <= 0){
            		continue;
            	}
                ans2 = max(ans2, grid[max(rowa, rowb)][j] - grid[max(rowa, rowb)][j + 1]);
            }
            cout << "MAX(ANS1, ANS2)" << max(ans1, ans2) << "\n";
            ans = min(ans, min(ans1, ans2));
        }else if((cola < colb && rowa > rowb) || (colb < cola && rowb > rowa)){
            int ans1, ans2;
            ans1 = ans2 = 0;
            for(int j = min(cola, colb); j < max(cola, colb); j++){
            	if(grid[max(rowa, rowb)][j] - grid[max(rowa, rowb)][j + 1] <= 0){
            		continue;
            	}
                ans1 = max(ans1, grid[max(rowa, rowb)][j] - grid[max(rowa, rowb)][j + 1]);
            }
            for(int j = min(rowa, rowb); j < max(rowa, rowb); j++){
            	if(grid[j][max(cola, colb)] - grid[j + 1][max(cola, colb)] <= 0){
            		continue;
            	}
                ans2 = max(ans2, grid[j][max(cola, colb)] - grid[j + 1][max(cola, colb)]);
            }
            ans = min(ans, min(ans1, ans2));
            ans1 = ans2 = 0;
            for(int j = min(cola, colb); j < max(cola, colb); j++){
            	if(grid[min(rowa, rowb)][j] - grid[min(rowa, rowb)][j + 1] <= 0){
            		continue;
            	}
                ans1 = max(ans1, grid[min(rowa, rowb)][j] - grid[min(rowa, rowb)][j + 1]);
            }
            for(int j = min(rowa, rowb); j < max(rowa, rowb); j++){
            	if(grid[min(cola, colb)][j] - grid[min(cola, colb)][j + 1] <= 0){
            		continue;
            	}
                ans2 = max(ans2, grid[min(cola, colb)][j] - grid[min(cola, colb)][j + 1]);
            }
            ans = min(ans, min(ans1, ans2));
        }
        cout << ans << "\n";
        cout << "------------------------------------\n";
    }
    return 0;
}