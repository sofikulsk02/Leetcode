class Solution {
public:
    void permutation(vector<int>&nums,int i,vector<vector<int>>&ans){
        int n=nums.size();
        if(i==n-1){
            ans.push_back(nums);
            return;
        }
        for(int idx=i;idx<n;idx++){
             swap(nums[idx],nums[i]);
             permutation(nums,i+1,ans);
             swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>ans;
         permutation(nums,0,ans);
         return ans;
    }
};