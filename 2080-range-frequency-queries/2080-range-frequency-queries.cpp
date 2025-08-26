class RangeFreqQuery {
public:
    vector<unordered_map<int,int>>st;
    vector<int>nums;
    int n;
    RangeFreqQuery(vector<int>& arr) {
        n=arr.size();
        st.resize(4*n);
        buildTree(arr,0,0,n-1);
    }
    unordered_map<int,int>addMaps(unordered_map<int,int>&mp1,unordered_map<int,int>&mp2){
        unordered_map<int,int>mp;
        for(auto ele:mp1){
            mp.insert(ele);
        }
        for(auto x:mp2){
            int key=x.first;
            int freq=x.second;
            if(mp.find(key)==mp.end()){
                   mp.insert(x);
            }
            else{
                mp[key]+=freq;
            }
        }
        return mp;
    }
    void buildTree(vector<int>&nums,int i,int lo,int hi){
        if(lo==hi){
            st[i][nums[lo]]=1;
            return;
        }
        int mid=lo+(hi-lo)/2;
        buildTree(nums,2*i+1,lo,mid);
        buildTree(nums,2*i+2,mid+1,hi);
        st[i]=addMaps(st[2*i+1],st[2*i+2]);
    }
    int getfreq(int i,int lo,int hi,int &l,int & r,int &value){
        if(l>hi || r<lo) return 0;
        if(l<=lo && hi<=r){
            if(st[i].find(value)==st[i].end()) return 0;
            else return st[i][value];
        }
        int mid=lo+(hi-lo)/2;
        int leftAns=getfreq(2*i+1,lo,mid,l,r,value);
        int rightAns=getfreq(2*i+2,mid+1,hi,l,r,value);
        return leftAns+rightAns;
    }
    int query(int left, int right, int value) {
        return getfreq(0,0,n-1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */