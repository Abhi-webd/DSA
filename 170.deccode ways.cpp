class Solution {
public:
    int numDecodings(string s) {
        if(s.at(0) == '0'){
            return 0;
        }
        
        vector<int> dp(s.length()+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1 ; i < s.length() ; i++){
            if(s.at(i) == '0'){
                if(s.at(i-1) == '0'){
                    return 0;
                }
                else if(s.at(i-1) > '2'){
                    return 0;
                }
                else{
                    dp[i+1] = dp[i-1];
                }
            }
            else if(s.at(i-1) > '2' || (s.at(i-1) == '2' && s.at(i) > '6')){
                dp[i+1] = dp[i];
            }
            else{
                if(s.at(i-1) != '0'){
                    dp[i+1] = dp[i] + dp[i-1];
                }
                else{
                    dp[i+1] = dp[i];
                }
            }
        }
        return dp[s.length()];
    }
};
