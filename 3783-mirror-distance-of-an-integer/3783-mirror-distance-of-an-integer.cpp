class Solution {
public:
    int mirrorDistance(int n) {
        int ans=0;
        int d=n;
        while(n){
            int ele=n%10;
            ans=ans*10+ele;
            n/=10;
        }
        return abs(ans-d);
    }
};