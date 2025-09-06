class Solution {
public:
    void permutation(vector<int>&nums,int i,vector<vector<int>>&ans){
        int n=nums.size();
        if(i==n-1){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int idx=i;idx<n;idx++){
            if(s.count(nums[idx])) continue;
            else{
                s.insert(nums[idx]);
            }
             swap(nums[idx],nums[i]);
             permutation(nums,i+1,ans);
             swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>>ans;
         permutation(nums,0,ans);
         return ans;
    }
};