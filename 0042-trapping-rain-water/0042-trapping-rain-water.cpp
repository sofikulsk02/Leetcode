class Solution {
public:
    vector<int> leftMaxEle(vector<int>& height,int &n){
        vector<int>leftEle(n);
        leftEle[0]=height[0];
        for(int i=1;i<n;i++){
            leftEle[i]=max(leftEle[i-1],height[i]);
        }
        return leftEle;
    }
    vector<int> rightMaxEle(vector<int>& height,int &n){
        vector<int>rightEle(n);
        rightEle[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightEle[i]=max(rightEle[i+1],height[i]);
        }
        return rightEle;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax=leftMaxEle(height,n);
        vector<int>rightMax=rightMaxEle(height,n);
        int ans=0;
        for(int i=0;i<n;i++){
            int w=min(leftMax[i],rightMax[i])-height[i];
            ans+=w;
        }
        return ans;
    }
};