class Solution {
public:
    bool checkDivisibility(int n) {
        int product=1;
        int sum=0;
        int nCopy= n;
        while(nCopy>0){
            product*=(nCopy%10);
            sum+=(nCopy%10);
            nCopy/=10;
        }
        int dividend= product + sum;
        return (n%dividend==0);
    }
};