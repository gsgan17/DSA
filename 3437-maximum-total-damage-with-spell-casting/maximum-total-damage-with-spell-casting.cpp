class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        map<int, long long> powerMap;

        for(int i=0; i<n; i++){
            if(powerMap.find(power[i])==powerMap.end()){
                powerMap[power[i]]=power[i];
            } else{
                powerMap[power[i]]+=power[i];
            }
        }

        // for(auto it: powerMap){
        //     cout << it.first << " " << it.second << endl;
        // }

        n= powerMap.size();

        vector<int> power2;

        for(auto it: powerMap){
            power2.push_back(it.first);
        }

        vector<long long> dp(n+1, 0);
        dp[0]=0;
        for(int i=1; i<=n; i++){
            int pickIndex=0;
            int notPickIndex=i-1;
            for(int j=i-1; j>=1; j--){
                if(abs(power2[j-1]-power2[i-1])>2){
                    pickIndex=j;
                    break;
                }
            }
            dp[i]=max(dp[i], dp[notPickIndex]);
            if(pickIndex!=-1){
                dp[i]=max(dp[i], dp[pickIndex]+powerMap[power2[i-1]]);
            } 
        }

        for(auto it: dp){
            cout << it << " "; 
        }
        cout << endl;

        return dp[n];
    }
};