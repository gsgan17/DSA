class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();

        int first = nums[0];

        int l=0;
        int r= n-1;
        int soln= first;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]>first){
                l=mid+1;
            } else if(nums[mid]<first){
                soln= min(soln, nums[mid]);
                r=mid-1;
            } else{
                soln = min(soln, nums[mid]);
                l=mid+1;
            }
        }

        return soln;
    }
};