class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int minima=0;
        int maxima=0;
        int sum = accumulate(nums.begin(), nums.end(), 0);

        minima= -sum;
        maxima= sum;

        map<int, map<int, int>> dp;

        for(int i=0; i<=n; i++){
            for(int j=minima; j<=maxima; j++){
                dp[i][j]=0;
            }
        }

        dp[1][nums[0]]++;
        dp[1][-nums[0]]++;

        for(int i=2; i<=n; i++){
            for(int j=minima; j<=maxima; j++){
                dp[i][j]+=dp[i-1][j-nums[i-1]];
                dp[i][j]+=dp[i-1][j+nums[i-1]];
            }
        }

        // for(int i=0; i<=n; i++){
        //     for(int j=minima; j<=maxima; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n][target];
    }
};