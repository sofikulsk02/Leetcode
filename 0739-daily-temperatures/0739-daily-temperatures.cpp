class Solution {
public:
    stack<pair<int,int>>st;
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i]>st.top().first){
                int stackT=st.top().first;
                int stackI=st.top().second;
                ans[stackI]=i-stackI;
                st.pop();
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};