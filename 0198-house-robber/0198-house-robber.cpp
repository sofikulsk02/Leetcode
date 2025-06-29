class Solution {
public:
    vector<int>dp;
    int maxProfit(vector<int>&arr,int i){
        if(i==arr.size()-1) return arr[i];
        if(i==arr.size()-2) return max(arr[i],arr[i+1]);
        if(dp[i]!=-1) return dp[i];
        dp[i]=max((arr[i]+maxProfit(arr,i+2)),maxProfit(arr,i+1));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        return maxProfit(nums,0);
    }
};