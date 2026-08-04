// goshawk17
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
	void solveUtil() {
		long long n, c, k;
		cin >> n >> c >> k;
		vector<long long> a(n);
		for (long long i = 0; i < n; i++) {
			cin >> a[i];
		}
 
		sort(a.begin(), a.end());
 
		for (long long i = 0; i < n; i++) {
			if (c >= a[i]) {
				long long incFactor = min(c - a[i], k);
				c += (incFactor + a[i]);
				k -= incFactor;
			} else {
				break;
			}
		}
 
		cout << c << "\n";
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