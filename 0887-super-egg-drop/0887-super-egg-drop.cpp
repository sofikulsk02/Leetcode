class Solution {
public:
   int minAttempt(int k,int n,vector<vector<int>>&dp){
    if(k==1) return n;
    if(n==0) return 0;
    if(dp[n][k]!=-1) return dp[n][k];
    int lo=1,hi=n,ans=n;
    while(lo<=hi){
        int mid=(hi+lo)/2;
        int breaks=minAttempt(k-1,mid-1,dp);
        int notBreak=minAttempt(k,n-mid,dp);
        int worst=max(breaks,notBreak)+1;
        ans=min(ans,worst);

        if(breaks>notBreak){
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return dp[n][k]=ans;
   }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return minAttempt(k,n,dp);
    }
};