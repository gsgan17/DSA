class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();

        int soln = -1e9;
        int temp = 1;

        for(int i=0; i<n; i++){
            temp*=nums[i];
            soln= max(temp, soln);
            if(temp==0){
                temp=1;
            }
        }
        temp = 1;
        for(int i=n-1; i>=0; i--){
            temp*=nums[i];
            soln= max(temp, soln);
            if(temp==0){
                temp=1;
            }
        }

        return soln;
    }
};