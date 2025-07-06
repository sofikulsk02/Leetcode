class Solution {
public:
    void fillSeive(vector<bool>& seive,int n){
        for(int i=2;i<=n;i++){
            if(seive[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    seive[j]=0;
                }
            }
        }
    }
    int countPrimes(int n) {
       if(n<2) return 0;
        n-=1;
        vector<bool> seive(n+1,1);
        seive[0]=seive[1]=0;
        fillSeive(seive,n);
        int count=0;
        for(int i=2;i<=n;i++){
            if(seive[i]==1) count++;
        }
        return count;
    }
};