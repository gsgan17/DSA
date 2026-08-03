class Solution {
public:
    int hammingWeight(int n) {
        int soln=0;
        while(n>0){
            if(n&1){
                soln++;
                n=n>>1;
            } else{
                n=n>>1;
            }
        }
        return soln;
    }
};