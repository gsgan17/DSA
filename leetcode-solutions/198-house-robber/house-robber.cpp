class Solution {
public:
    int rob(vector<int>& nums) {
        // dp(n) = max money in first n houses.
        // BC = dp(0) = 0
        // Transitions = dp(n) = max(dp(n-1), dp(n-2) + nums[n - 1])

        int n = nums.size();
        vector<int> dp(n + 1, 0);

        dp[1] = nums[0];

        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }

        return dp[n];
    }
};