#include <iostream>
#include <iomanip>
using namespace std;

#define ll long long
int main(void){
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sum /= n;
    double curSum = arr[0];
    double maxSum = arr[0];
    int numElem = 1;
    for(int i = 1; i < n; i++){
        if((double)(curSum + arr[i]) / numElem > arr[i]){
            curSum = (curSum + arr[i]) / numElem;
        }else{
            numElem = 1;
            curSum = arr[i];
        }
        maxSum = max(maxSum, curSum);

    }
    double a = sum - maxSum;
    cout << sum << "\n";
    cout << setprecision(4) << a << "\n";
    return 0;
}