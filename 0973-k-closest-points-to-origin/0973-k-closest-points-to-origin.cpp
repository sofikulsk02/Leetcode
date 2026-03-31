class Solution {
public:
    typedef pair<long long,pair<int,int>>pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            long long dis=x*x+y*y;
            pq.push({dis,{x,y}});
        }
        while(k--){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};