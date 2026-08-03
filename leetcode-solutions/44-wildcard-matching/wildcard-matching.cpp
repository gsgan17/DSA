class Solution {
public:
    bool isMatch(string s, string p) {
        if(p=="*"){
            return true;
        }

        int n= s.size();
        int m= p.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        dp[0][0]=true;

        int g= 0;
        while(g<m && p[g]=='*'){
            dp[0][g+1]=true;
            g++;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                } else if(p[j-1]=='*'){
                    // dp[i][j]=(dp[i-1][j] | dp[i-1][j-1]);
                    for(int k=0; i-k>=0; k++){
                        dp[i][j]= dp[i][j] | (dp[i-k][j] | dp[i-k][j-1]);
                        if(dp[i][j]){
                            break;
                        }
                    }
                } else{
                    dp[i][j]=(s[i-1]==p[j-1]) & dp[i-1][j-1];
                }
            }
        }

        // for(auto it1: dp){
        //     for(auto it2: it1){
        //         cout << it2 << " ";
        //     }
        //     cout << endl;
        // }

        return dp[n][m];
    }
};