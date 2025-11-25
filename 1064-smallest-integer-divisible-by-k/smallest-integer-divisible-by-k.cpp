class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long dividend = 1;
        int length= 1;
        set<int> seen;

        while(!seen.count(dividend)){
            if(dividend%k==0){
                return length;
            } else{
                seen.insert(dividend);
                length++;
                dividend=dividend*10 + 1;
                dividend=dividend%k;
            }
        }

        return -1;
    }
};