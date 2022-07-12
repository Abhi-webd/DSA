int helper(string s, string t , int m, int n, vector<vector<int>> &dp){
      if(m == -1){
          return n+1;
      }
      if(n == -1){
          return m+1;
      }
      if(dp[m][n] != -1){
          return dp[m][n];
      }
      if(s[m] == t[n]){
          return dp[m][n] = helper(s,t,m-1,n-1,dp);
      }
      else{
          int option1 = 1+helper(s,t,m-1,n-1,dp);
          int option2 = 1+helper(s,t,m-1,n,dp);
          int option3 = 1+helper(s,t,m,n-1,dp);
          return dp[m][n] = min(option1,min(option2,option3));
      }
  }
  
    int editDistance(string s, string t) {
        // Code here
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
       return helper(s,t,s.size()-1,t.size()-1,dp);
    }
