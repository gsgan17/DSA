class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mod = 1e9 + 7;
        int n = complexity.size();
        int first = complexity[0];
        long long permutations = 1;
        for(int i=1; i<n; i++){
            permutations*=i;
            permutations%=mod;
            if(complexity[i]<=first){
                return 0;
            }
        }
        return (int)(permutations);
    }
};