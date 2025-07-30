class Solution {
public:
  void helper(vector<int>&nums,vector<vector<int>>&finalAns,vector<int>ans,int idx){
    if(idx==nums.size()){
        finalAns.push_back(ans);
        return;
    }
    helper(nums,finalAns,ans,idx+1);
    ans.push_back(nums[idx]);
      helper(nums,finalAns,ans,idx+1);
  }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>finalAns;
        vector<int>ans;
        helper(nums,finalAns,ans,0);
        return finalAns;
    }
};