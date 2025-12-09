class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();
        map<int, int> left, right;
        
        for(int i=n-1; i>=2; i--){
            right[nums[i]]++;
        }
        left[nums[0]]++;
        long long triplets = 0;
        for(int i=1; i<n-1; i++){
            int middle = nums[i];
            int rl = nums[i]*2;
            int rr = rl;
            int rc = right[rr];
            int lc = left[rl];
            triplets+= ((long long)(rc)*(long long)(lc));
            right[nums[i+1]]--;
            left[nums[i]]++;
            triplets %= mod;
        }
        return (int)(triplets);
    }
};