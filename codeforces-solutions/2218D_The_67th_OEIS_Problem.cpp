// goshawk17
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
	void solveUtil() {
		long long n;
		cin >> n;
		for (long long i = 1; i <= 2 * n; i += 2) {
			cout << (1LL * i * (i + 2)) << " ";
		}
		cout << "\n";
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