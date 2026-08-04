// goshawk17
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
	void solveUtil() {
		long long n;
		cin >> n;
		vector<long long> a(n);
 
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
 
		for (int i = 0; i < n; i++) {
			long long x = 0, b = 0;
			for (int j = i + 1; j < n; j++) {
				if (a[j] > a[i]) {
					x++;
				} else if (a[j] < a[i]) {
					b++;
				}
			}
			long long soln = -1;
			if (x > b) {
				soln = x;
			} else {
				soln = b;
			}
			cout << soln << " ";
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