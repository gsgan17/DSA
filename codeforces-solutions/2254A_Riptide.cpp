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
    int a, b, c;
    cin >> a >> b >> c;
    int rounds = 0;
 
    while (a != b && b != c && a != c) {
        int max_val = max({a, b, c});
        int min_val = min({a, b, c});
 
        if (a == max_val) {
            a--;
        } else if (b == max_val) {
            b--;
        } else {
            c--;
        }
 
        if (a == min_val) {
            a++;
        } else if (b == min_val) {
            b++;
        } else {
            c++;
        }
 
        rounds++;
    }
 
    cout << rounds << endl;
}