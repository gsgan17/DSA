class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int a = 0, b=totalSum;
        int partitions = 0;

        for(int i=0; i<n-1; i++){
            a+=nums[i];
            b-=nums[i];
            if((a+b)%2==0){
                partitions++;
            }
        }

        return partitions;
    }
};