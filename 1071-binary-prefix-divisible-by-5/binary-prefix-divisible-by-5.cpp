class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n= nums.size();
        vector<bool> soln(n, false);

        int currNum = 0;

        for(int i=0; i<n; i++){
            currNum <<=1;
            currNum |=nums[i];
            currNum%=5;
            soln[i]=(currNum%5==0);
        }

        return soln;
    }
};