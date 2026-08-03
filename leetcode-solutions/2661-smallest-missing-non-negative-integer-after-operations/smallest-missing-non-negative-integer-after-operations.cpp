class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n= nums.size();
        if(value==1){
            return n;
        }
        vector<int> check(value, 0);
        for(int i=0; i<n; i++){
            nums[i]=((nums[i]%value)+2*value)%value;

            check[nums[i]%value]++;
        }

        for(int i=0; i<n; i++){
            if(check[i%value]==0){
                return i;
            } 
            check[i%value]--;
        }

        return n;
    }
};