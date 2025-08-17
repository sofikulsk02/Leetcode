class Solution {
public:
    vector<string> ways(string s,int i,unordered_set<string>&hs,vector<vector<string>>&dp){
                int n=s.length();
                if(i==n) return {""};
                if(!dp[i].empty()) return dp[i];
                vector<string>ans;
                string temp="";
                for(int j=i;j<n;j++){
                    temp+=s[j];
                    if(hs.find(temp)!=hs.end()){
                        vector<string>sub=ways(s,j+1,hs,dp);
                        for(string s:sub){
                            if(s=="") ans.push_back(temp);
                            else ans.push_back(temp+" "+s);
                        }
                    }
                }
                return dp[i]=ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>hs;
        vector<vector<string>> dp(s.length());
        for(int i=0;i<wordDict.size();i++){
            hs.insert(wordDict[i]);
        }
        return ways(s,0,hs,dp);
    }
};