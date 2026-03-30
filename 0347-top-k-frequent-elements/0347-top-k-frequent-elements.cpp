class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(auto x:nums){
            mp[x]++;
        }
        for(auto x:mp){
            int ele=x.first;
            int freq=x.second;
            pq.push({freq,ele});
        }
        while(k--){
            int ele=pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};