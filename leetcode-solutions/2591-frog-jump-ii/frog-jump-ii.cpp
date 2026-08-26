class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if (n <= 3) {
            return stones[n - 1] - stones[0];
        }

        int max_cost = 0;

        for (int i = 0; i < n; i+=2) {
            int ei = i;
            int oi = i + 1;
            if (ei - 2 >= 0) {
                max_cost = max(max_cost, stones[ei] - stones[ei - 2]);
            }
            if (oi - 2 >= 0) {
                max_cost = max(max_cost, stones[oi] - stones[oi - 2]);
            }
        }

        return max_cost;
    }
};