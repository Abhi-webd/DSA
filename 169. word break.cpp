class Solution {
public:
    
    
    bool helper(int i , string s, set<string> &st,vector<int> &dp){
        if(i == s.size()){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        string temp;
        for(int j = i ; j < s.size() ; j++){
            temp += s[j];
            if(st.find(temp) != st.end()){
                if(helper(j+1,s,st,dp)){
                    return dp[i] = 1;
                }
            }
        }
        return dp[i] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<int> dp(301,-1);
        for(auto i : wordDict){
            st.insert(i);
        }
        return helper(0,s,st,dp);
    }
};
