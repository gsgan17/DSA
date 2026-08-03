class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n= nums.size();

        vector<vector<int>> dp(n+1, vector<int>(3, 0));

        for(int i=1; i<=n; i++){
            for(int j=0; j<3; j++){
                dp[i][j]=max(dp[i][j], dp[i-1][j]);
                int sum = dp[i-1][j]+nums[i-1];
                int mod = sum%3;
                dp[i][mod]=max(dp[i][mod], sum);
            }
        }

        return dp[n][0];
    }
};