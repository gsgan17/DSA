// goshawk17
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
private:
public:
    static void solve();
};
 
int main() {
    // Single test
    Solution::solve();
    
    // Multiple tests
    // int t;
    // cin >> t;
    // while (t--) {
    //     Solution::solve();
    // }
 
    return 0;
}
 
void Solution::solve() {
    int a;
    cin >> a;
 
    if(a%2 == 0 && a > 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}