class Solution {
private:
    bool containsDuplicates(map<char, int>& f){
        for(auto it: f){
            if(it.second>1){
                return true;
            }
        }
        return false;
    }
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char, int> f;
        int soln = 0;

        int l=0, r=0;

        while(r<n){
            f[s[r]]++;
            while(l<n && l<r && containsDuplicates(f)){
                f[s[l]]--;
                l++;
            }
            soln = max(soln, r-l+1);
            r++;
        }

        return soln;
    }
};