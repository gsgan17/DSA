// goshawk17
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
private:
public:
    static void solve();
};
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    // Single test
 
    // Solution::solve();
    
    // Multiple tests
    
    int t;
    cin >> t;
    while (t--) {
        Solution::solve();
    }
 
    return 0;
}
 
void Solution::solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    int b = 1;
    for(int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            b++;
        }
    }
 
    int min_delta = 0;
    for (int i = 1; i <= n-2; i++) {
        bool left_diff = (s[i] != s[i - 1]);
        bool right_diff = (s[i] != s[i + 1]);
        bool ends_diff = (s[i + 1] != s[i - 1]);
 
        int del = 0;
        if (left_diff) {
            del--;
        } 
        if (right_diff) {
            del--;
        }
        if (ends_diff) {
            del++;
        }
 
        if (del < min_delta) {
            min_delta = del;
        }
    }
 
    cout << (b + min_delta) << "\n";
}