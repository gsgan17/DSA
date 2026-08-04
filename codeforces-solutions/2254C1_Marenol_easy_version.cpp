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
    string s0, s1;
    cin >> s0;
    cin >> s1;
 
    bool possible = true;
 
    int zeros[2] = {0, 0}, ones[2] = {0, 0};
 
    for(int i=0; i<n; i+=2){
        if(s0[i] == '0') zeros[0]++;
        else ones[0]++;
 
        if(s1[i] == '0') zeros[1]++;
        else ones[1]++;
    }
 
    if (zeros[0] != zeros[1] || ones[0] != ones[1]) {
        possible = false;
    }
 
    zeros[0] = zeros[1] = 0;
    ones[0] = ones[1] = 0;
 
    for(int i=1; i<n; i+=2){
        if(s0[i] == '0') zeros[0]++;
        else ones[0]++;
 
        if(s1[i] == '0') zeros[1]++;
        else ones[1]++;
    }
 
    if (zeros[0] != zeros[1] || ones[0] != ones[1]) {
        possible = false;
    }
 
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}