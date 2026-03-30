class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            int diff=abs(x-arr[i]);
            pq.push({diff,arr[i]});
        }
        while(k--){
           int ele=pq.top().second;
           ans.push_back(ele);
           pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};