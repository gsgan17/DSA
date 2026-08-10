// Author: Gagandeep Singh

#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

namespace IntroductoryProblems {
    
    void weird_algorithm() {
        long long n;
        cin >> n;
        while (n != 1) {
            cout << n << " ";
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
        }
        cout << n << '\n';
    }

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // For local stdio
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tests = 1;
    // cin >> tests;
    while (tests--) {
        IntroductoryProblems::weird_algorithm();
    }

    return 0;
}
