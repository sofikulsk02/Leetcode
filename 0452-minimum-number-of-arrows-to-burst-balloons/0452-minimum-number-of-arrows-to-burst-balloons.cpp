class Solution {
public:
    static bool cmp(vector<int>a,vector<int>b){
    return a[1]<b[1];
   }
    int findMinArrowShots(vector<vector<int>>& points) {
         int n=points.size();
        sort(points.begin(),points.end(),cmp);
        int ans=0;
        int lastInterval=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]<=lastInterval){
                ans++;
            }
            else{
                lastInterval=points[i][1];
            }
        }
        return points.size()-ans;
    }
};