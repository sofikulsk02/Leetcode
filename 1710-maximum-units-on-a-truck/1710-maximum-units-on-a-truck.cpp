class Solution {
public:
     static bool cmp(pair<int,int> p1,pair<int,int> p2){
        // double r1=p1.second*1.0/p1.first*1.0;
        // double r2=p2.second*1.0/p2.first*1.0;
        // return r1>r2;
        return p1.second>p2.second;
     }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>>arr;
        int n=boxTypes.size();
        int result=0;
        for(auto ele:boxTypes){
            arr.push_back({ele[0],ele[1]});
        }
        sort(arr.begin(),arr.end(),cmp);
        for(int i=0;i<n;i++){
            if(arr[i].first<=truckSize){
                result+=arr[i].first*arr[i].second;
                truckSize-=arr[i].first;
            }
            else{
                result+=truckSize*arr[i].second;
                break;
            }
        }
        return result;
    }
};