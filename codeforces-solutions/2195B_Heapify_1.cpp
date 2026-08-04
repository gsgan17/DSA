// goshawk17
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
	void solveUtil() {
		int n;
		cin >> n;
 
		vector<int> p(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
		}
 
		map<int, priority_queue<int, vector<int>, greater<int>>> m;
 
		for (int i = 1; i <= n; i += 2) {
			int mul = 1;
			while (i * mul <= n) {
				m[i].push(p[i * mul]);
				mul <<= 1;
			}
		}
 
		// for (auto it : m) {
		// 	cout << it.first << endl << endl;
		// 	while (!it.second.empty()) {
		// 		cout << it.second.top() << " ";
		// 		it.second.pop();
		// 	}
		// 	cout << endl << endl << endl;
		// }
 
		int curr = 1;
		for (int ind = 1; ind <= n; ind++) {
			int i = ind;
			// cout << i << endl;
			while (i % 2 == 0) {
				i >>= 1;
			}
			if (!m[i].empty() && m[i].top() == curr) {
				curr++;
				m[i].pop();
			} else {
				// cout << m[i].empty() << endl;
				if (!m[i].empty()) {
					// cout << m[i].top() << endl;
					// cout << curr << endl;
					// cout << i << endl;
				}
				cout << "NO\n";
				return;
			}
		}
 
		cout << "YES\n";
		// cout << endl << endl;
 
	}
 
	void solve() {
		int t;
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