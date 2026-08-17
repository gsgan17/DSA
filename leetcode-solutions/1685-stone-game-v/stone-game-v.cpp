class Solution {
public:
    vector<int> get_prefix_sum_vector(int& n, vector<int>& stoneValue) {
        vector<int> prefix_sum(n, 0);

        for(int i = 0; i < n; i++) {
            if (i == 0) prefix_sum[i] = stoneValue[i];
            else prefix_sum[i] = stoneValue[i] + prefix_sum[i-1];
        }

        return prefix_sum;
    }

    int get_prefix_sum(int l, int r, vector<int>& prefix_sum) {
        if (l == 0) {
            return prefix_sum[r];
        }
        return prefix_sum[r] - prefix_sum[l - 1];
    }

    void debug(vector<vector<int>>& matrix) {
        for (auto it1 : matrix) {
            for (auto it2 : it1) {
                cout << it2 << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        vector<int> prefix_sum = get_prefix_sum_vector(n, stoneValue);

        // for (int i = 0; i < n; i++) {
        //     dp[i][1] = stoneValue[i];
        // }

        for (int j = 2; j <= n; j++) {
            for (int i = 0; i <= (n - j); i++) {
                int sum = -1;
                for (int k = i; k <= i + j - 2; k++) {
                    int left_sum = get_prefix_sum(i, k, prefix_sum);
                    int right_sum = get_prefix_sum(k+1, i + j - 1, prefix_sum);
                    if (left_sum > right_sum) {
                        sum = max(sum, right_sum + dp[k+1][i + j - k - 1]);
                    } else if (right_sum > left_sum) {
                        sum = max(sum, left_sum + dp[i][k-i+1]);
                    } else {
                        sum = max(sum, right_sum + dp[k+1][i + j - k - 1]);
                        sum = max(sum, left_sum + dp[i][k-i+1]);
                    }
                }
                dp[i][j] = sum;
            }
        }

        // debug(dp);

        return dp[0][n];
    }
};