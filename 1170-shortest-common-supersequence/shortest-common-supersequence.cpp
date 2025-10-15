class Solution {
private:
    string scs(string a, string b){
        int n= a.size();
        int m= b.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                } else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string soln = "";

        int i=n, j=m;
        while(i!=0 && j!=0){
            if(a[i-1]==b[j-1]){
                soln.push_back(a[i-1]);
                i--;
                j--;
            } else{
                if(dp[i-1][j]==dp[i][j]){
                    soln.push_back(a[i-1]);
                    i--;
                } else {
                    soln.push_back(b[j-1]);
                    j--;
                }
            }
        }

        while(i>0){
            soln.push_back(a[i-1]);
            i--;
        }

        while(j>0){
            soln.push_back(b[j-1]);
            j--;
        }

        reverse(soln.begin(), soln.end());

        return soln;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string l= scs(str1, str2);
        return l;
    }
};