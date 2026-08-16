class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int freq[3] = {0};
        for (const int num: stones)
            ++freq[num % 3];

        int f1 = freq[1], f2 = freq[2];
        if (f1) {
            int cnt = 1;
            --f1;
            int minf = min(f1, f2);
            f1 -= minf, f2 -= minf;
            if (f1) {
                --f1;
                cnt = 0;
            }
            if (f1 + f2 && (cnt + freq[0]) % 2)
                return true;
        }

        f1 = freq[1], f2 = freq[2];
        if (f2) {
            int cnt = 1;
            --f2;
            int minf = min(f1, f2);
            f1 -= minf, f2 -= minf;
            if (f2) {
                --f2;
                cnt = 0;
            }
            if (f1 + f2 && (cnt + freq[0]) % 2)
                return true;
        }
        return false;
    }
};