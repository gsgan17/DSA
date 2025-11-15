class Solution {
public:
    int reverseBits(int n) {
        int soln = 0;

        for(int i=0; i<32; i++){
            soln = (soln<<1) | n&1;
            n= n>>1;
        }

        return soln;
    }
};