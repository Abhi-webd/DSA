vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int result = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(mat[i-1][j-1]){
                    dp[i][j] = min({ dp[i-1][j-1], dp[i-1][j], dp[i][j-1] }) + 1;
                }
                result = max(result, dp[i][j]);
            }
        }
        
        return result;
