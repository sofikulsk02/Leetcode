class Solution {
public:
    vector<int> leftMaxHeight(vector<int>& height,int &n){
        vector<int>leftMax(n);
        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        return leftMax;
    }
    vector<int> rightMaxHeight(vector<int>& height,int & n){
        vector<int>rightMax(n);
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        return rightMax;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax=leftMaxHeight(height,n);
        vector<int>rightMax=rightMaxHeight(height,n);
        int ans=0;
        for(int i=0;i<height.size();i++){
            int h=min(rightMax[i],leftMax[i])-height[i];
            ans+=h;
        }
        return ans;
    }
};