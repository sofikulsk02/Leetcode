class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int i=0,j=n-1;
        int boat=0;
        sort(people.begin(),people.end());
        while(i<=j){
            if((people[i]+people[j])<=limit){
                boat++;
                i++;
                j--;
            }
            else{
                boat++;
                j--;
            }
        }
        return boat;
    }
};