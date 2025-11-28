class Solution {
public:
void solve(int s, int e, vector<int>& dp, vector<vector<int>>& adj,int &soln,vector<int>& values,int &k){
    dp[s]=values[s];
    int div= k;
    for(int i=0; i<adj[s].size(); i++){
        if(adj[s][i]!=e){
            solve(adj[s][i],s,dp,adj,soln,values,k);
            dp[s]=dp[s]+dp[adj[s][i]];
            dp[s]%=k;
        }
    }
    if((dp[s]%k)==0){
        dp[s]=0;
        soln++;
    }
}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int m = edges.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<m; i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int soln=0;
        vector<int>dp(n,0);
        solve(0,-1,dp,adj,soln,values,k);    
        return soln;
    }
};