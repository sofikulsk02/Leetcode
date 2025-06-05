class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total=INT_MAX;
        int sum=0;
        int start=0,end=0;
        int n=nums.size();
        while(end<n){
            sum+=nums[end]; //add number to sum
            //window length ko decrease karsakte hai
            while(sum>=target){
                total=min(total,end-start+1);
                sum-=nums[start++]; 
            }
            //window length ko increase karo
            end++;
        }
        return total==INT_MAX? 0: total;
    }
};