class Solution {
public:
    void helper(vector<int>&nums,vector<vector<int>>&finalans,vector<int>&ans,int idx,int target,int sum){
        int n=nums.size();
        if(sum == target){
            finalans.push_back(ans);
            return;
        }
        if(sum > target || idx == n){
            return;
        }
        ans.push_back(nums[idx]);
        helper(nums, finalans, ans, idx, target, sum + nums[idx]);
        ans.pop_back();

        helper(nums, finalans, ans, idx + 1, target, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>finalans;
        vector<int>ans;
        helper(candidates,finalans,ans,0,target,0);
        return finalans;
    }
};