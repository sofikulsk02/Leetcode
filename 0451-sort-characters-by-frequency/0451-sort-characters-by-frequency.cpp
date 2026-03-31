class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        for(auto ch:s){
            mp[ch]++;
        }
        for(auto ch:mp){
            pq.push({ch.second,ch.first});
        }
        string  ans="";
        while(pq.size()!=0){
            char ch=pq.top().second;
            int t=pq.top().first;
            while(t--){
                ans+=ch;
            }
            pq.pop();
        }
        return ans;
    }
};