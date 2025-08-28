class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int>pq;
        priority_queue<int>c;
        for(auto ele:g){
            pq.push(ele);
        }
        for(auto ele:s){
            c.push(ele);
        }
        int count=0;
        while(!pq.empty() && !c.empty()){
            int need=pq.top();
            int cookie=c.top();
            if(need>cookie) pq.pop();
            else if(need<=cookie){
                count++;
                pq.pop();
                c.pop();
            }
        }
        return count;
    }
};