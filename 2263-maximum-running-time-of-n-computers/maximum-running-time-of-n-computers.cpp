class Solution {
public:
    bool isPossible(long long time, vector<int>& batteries, int n){
        int nb = batteries.size();
        long long tempTime = time*n;
        for(int i=0; i<nb; i++){
            tempTime-= min(time, (long long)(batteries[i]));
        }
        return tempTime<=0;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        int nb = batteries.size();
        long long total = accumulate(batteries.begin(), batteries.end(), 0ll);
        sort(batteries.begin(), batteries.end(), greater<int>());

        long long soln = -1;
        long long l = 0;
        long long r = total/n + 1;

        while(l<=r){
            long long mid = l + (r-l)/2;
            if(isPossible(mid, batteries, n)){
                soln = mid;
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }

        return soln;
    }
};