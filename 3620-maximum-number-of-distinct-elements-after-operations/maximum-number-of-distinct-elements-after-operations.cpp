class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n= nums.size();
        map<int, int> f;
        for(int i=0; i<n; i++){
            f[nums[i]]++;
        }

        int minima=-1e9;
        int maxima=1e9;

        int soln=0;
        for(auto it: f){
            int number = it.first;
            int frequency = it.second;
            int lower = max(minima, number-k);
            int higher = min(maxima, number+k);
            soln += min(frequency, higher-lower+1);
            minima=lower + min(frequency, higher-lower+1);

        }
        
        return min(soln, n);
    }
};