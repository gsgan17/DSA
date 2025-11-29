class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return abs(accumulate(nums.begin(), nums.end(), 0)-(accumulate(nums.begin(), nums.end(), 0)/k)*k); 
    }
};