class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) sum = (sum + num) % p;
        int t = sum % p;
        if (t == 0) return 0;
        unordered_map<int, int> nearest;
        nearest[0] = -1;
        int curr = 0, soln = n;
        for (int i = 0; i < n; ++i) {
            curr = (curr + nums[i]) % p;
            int req = (curr - t + p) % p;
            if (nearest.find(req) != nearest.end()) {
                soln = min(soln, i - nearest[req]);
            }
            nearest[curr] = i;
        }
        return soln == n ? -1 : soln;
    }
};
