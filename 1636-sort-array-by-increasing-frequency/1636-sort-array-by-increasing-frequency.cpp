class Solution {
public:
   typedef pair<int,int>pi;
   struct cmp{
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if(a.first!=b.first)
            return a.first > b.first;
            else
            {
                return a.second<b.second;
            }
    }
};
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        priority_queue<pi,vector<pi>,cmp>pq;
        vector<int>ans;
        for(auto x:nums){
            mp[x]++;
        }
        for(auto x:mp){
            int ele=x.first;
            int freq=x.second;
            pq.push({freq,ele});
        }
        while(!pq.empty()){
            int loop=pq.top().first;
            while(loop--){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};