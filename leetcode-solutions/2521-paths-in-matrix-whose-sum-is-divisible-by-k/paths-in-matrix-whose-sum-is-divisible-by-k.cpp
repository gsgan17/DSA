class Solution {
private:
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int mod = (int)(1e9 + 7);
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        int temp = 0;
        for(int i=0; i<m; i++){
            temp = (temp + grid[i][0])%k;
            dp[i][0][temp]=1;
        }

        temp = 0;
        for(int j=0; j<n; j++){
            temp = (temp + grid[0][j])%k;
            dp[0][j][temp]=1;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                for(int r= 0; r<k; r++){
                    dp[i][j][(r+grid[i][j])%k] = (dp[i][j][(r+grid[i][j])%k] + dp[i-1][j][r]) % mod;
                    dp[i][j][(r+grid[i][j])%k] = (dp[i][j][(r+grid[i][j])%k] + dp[i][j-1][r]) % mod;
                }
            }
        }

        // for(auto it1: dp){
        //     for(auto it2 : it1){
        //         for(auto it3: it2){
        //             cout << it3 << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        return dp[m-1][n-1][0];
    }
};