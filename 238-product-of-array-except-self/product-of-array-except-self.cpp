class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0]=nums[0];
        right[n-1]=nums[n-1];

        for(int i=1; i<n; i++){
            left[i]=left[i-1]*nums[i];
            right[n-1-i]=right[n-i]*nums[n-1-i];
        }

        for(auto it: left){
            cout << it << " ";
        }
        cout << endl;

        for(auto it: right){
            cout << it << " ";
        }
        cout << endl;

        vector<int> soln(n, 0);
        for(int i=0; i<n; i++){
            int low = i-1;
            int high = i+1;
            int temp = 1;
            if(low>=0){
                temp*=left[low];
            } 
            if(high<n){
                temp*=right[high];
            }
            soln[i]=temp;
            cout << i << " " << temp << endl;
        }

        return soln;
    }
};