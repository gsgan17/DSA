class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long dividend = 1;
        int length= 1;
        vector<bool> seen(k, false);

        while(!seen[dividend]){
            if(dividend%k==0){
                return length;
            } else{
                seen[dividend]=true;
                length++;
                dividend=dividend*10 + 1;
                dividend=dividend%k;
            }
        }

        return -1;
    }
};