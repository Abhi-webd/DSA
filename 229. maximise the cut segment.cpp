int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector <int> dp(10001);
        dp[x] = 1;
        dp[y] = 1;
        dp[z] = 1;
        for(int i=1; i<=n; i++){
            if(i-x >= 0 && dp[i-x])
                dp[i] = max(dp[i], 1+dp[i-x]);
            if(i-y >= 0 && dp[i-y])
                dp[i] = max(dp[i], 1+dp[i-y]);
            if(i-z >= 0 && dp[i-z])
                dp[i] = max(dp[i], 1+dp[i-z]);
        }
        return dp[n];
    }
