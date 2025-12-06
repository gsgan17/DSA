class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        deque<int> maxq, minq;
        int left = 0;
        long long total = 0;
        for (int i = 0; i < n; i++){
            while (!maxq.empty() && nums[maxq.back()] <= nums[i]){
                maxq.pop_back();
            }

            while (!minq.empty() && nums[minq.back()] >= nums[i]){
                minq.pop_back();
            }
            maxq.push_back(i);
            minq.push_back(i);

            while (nums[maxq.front()] - nums[minq.front()] > k){
                if (maxq.front() == left)
                    maxq.pop_front();
                if (minq.front() == left)
                    minq.pop_front();
                total = (total - dp[left] + mod) % mod;
                left++;
            }
            total = (total + dp[i]) % mod;
            dp[i + 1] = total;
        }
        return dp[n];
    }
};