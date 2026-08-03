class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefixSum = 0;
        long long soln = -1e17;
        vector<long long> kSum(k, 1e17);

        kSum[k - 1] = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            soln = max(soln, prefixSum - kSum[i % k]);
            kSum[i % k] = min(kSum[i % k], prefixSum);
        }

        return soln;
    }
};