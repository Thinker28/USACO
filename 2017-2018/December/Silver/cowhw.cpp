#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<unsigned long long, pair<unsigned long long, unsigned long long> >& a, pair<unsigned long long, pair<unsigned long long, unsigned long long> >& b) {
	return a.second.first * b.second.second > b.second.first * a.second.second;
}

int main(void){
	ifstream cin("homework.in");
	ofstream cout("homework.out");

	int n;
	cin >> n;
	unsigned long long arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	unsigned long long minval[n];
	minval[n - 1] = arr[n - 1];
	for(int i = n - 2; i >= 0; i--){
		minval[i] = min(minval[i + 1], arr[i]);
	}
	unsigned long long total = 0;
	for(int i = 0; i < n; i++){
		total += arr[i];
	}
	unsigned long long eaten = 0;
	vector<pair<unsigned long long, pair<unsigned long long, unsigned long long> > > vals;
	for(int k = 1; k <= n - 2; k++){
		eaten += arr[k - 1];
		unsigned long long realsum = total - eaten - minval[k];
		vals.push_back(make_pair(k, make_pair(realsum, n - k - 1)));
	}
	sort(vals.begin(), vals.end(), cmp);
	unsigned long long int max_numerator = -1, max_denominator = -1;
	for(int i = 0; i < vals.size(); i++){
		if (max_numerator == -1 || 
			max_numerator * vals[i].second.second == 
				max_denominator * vals[i].second.first) {
			max_numerator = vals[i].second.first;
			max_denominator = vals[i].second.second;
			cout << vals[i].first << "\n";
		} else {
			break;
		}
	}

	return 0;
}