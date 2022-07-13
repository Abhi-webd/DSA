int helper(string S1, string S2, int n , int m){
      vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans = 0;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
  }
  
    int longestPalinSubseq(string A) {
        //code here
        string B = A;
        reverse(B.begin(),B.end());
        return helper(A,B,A.size(),B.size());
    }
