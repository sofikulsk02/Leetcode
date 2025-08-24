class Solution {
public:
    void bfs(vector<vector<int>>&adj,vector<int>&vis,int node){
        vis[node]=1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(auto ele:adj[n]){
                if(!vis[ele]){
                    vis[ele]=1;
                    q.push(ele);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
       vector<vector<int>>adj(n);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
            adj[i].push_back(j);
            adj[j].push_back(i);
            } 
        }
       }
       vector<int>vis(n,0);
       int count=0;
       for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            bfs(adj,vis,i);
        }
       }
       return count;
    }
};