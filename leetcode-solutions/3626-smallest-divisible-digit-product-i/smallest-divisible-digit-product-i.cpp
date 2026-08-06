class Solution {
public:
    int digit_product(int n) {
        int prod = 1;
        while(n) {
            prod *= n%10;
            n /= 10;

            if (n == 0) {
                break;
            }
        }

        return prod;
    }
    int smallestNumber(int n, int t) {
        while(true) {
            if (digit_product(n) % t == 0) {
                return n;
            }
            n++;
        }
        return 0;
    }
};