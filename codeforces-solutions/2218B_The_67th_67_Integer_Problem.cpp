// goshawk17
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
	void solveUtil() {
		vector<int> a(7);
		for (int i = 0; i < 7; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long sum = 0;
		for (int i = 0; i < 6; i++) {
			a[i] *= -1;
			sum += a[i];
		}
		sum += a[6];
		cout << sum << "\n";
	}
 
	void solve() {
		long long t;
		cin >> t;
 
		while (t--) {
			solveUtil();
		}
 
		// solveUtil();
	}
};
 
int main() {
 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
#ifndef ONLINE_JUDGE
	// for getting input from input file.
	freopen("input.txt", "r", stdin);
	// for writing output to output file.
	freopen("output.txt", "w", stdout);
#endif
 
	Solution soln;
	soln.solve();
 
	return 0;
 
}