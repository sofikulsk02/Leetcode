class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int temp=i*i;
            ans=min(ans,solve(n-temp,dp));
        }
        dp[n]=ans+1;
      return dp[n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};