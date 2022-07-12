int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = M[i][0];
        }
        
        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int mid = dp[j][i-1];
                int above = 0;
                if(j-1 >=0){
                    above = dp[j-1][i-1];
                }
                int down = 0;
                if(j+1 < n){
                    down = dp[j+1][i-1];
                }
                int ma = max(mid,max(above,down));
                dp[j][i] = ma+M[j][i];
            }
        }
        
        
        int ma = 0;
        for(int i = 0 ; i < n ; i++){
            if(dp[i][m-1] > ma){
                ma = dp[i][m-1];
            }
        }
        return ma;
    }
