class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        while(k--){
            int ele=pq.top();
            pq.pop();
            int d=floor(ele/2);
            pq.push(ele-d);
        }
        int ans=0;
        while(!pq.empty()){
            int d=pq.top();
            ans+=d;
            pq.pop();
        }
        return ans;
    }
};