long long helper(int key[][3], int i , int j, int n,vector<vector<vector<long long>>> &dp){
	    if(i >= 4 || j >= 3 || i < 0 || j < 0){
	        return 0;
	    }
	    if(dp[i][j][n] != -1){
	        return dp[i][j][n];
	    }
	    if(key[i][j] == -1){
	        return 0;
	    }
	    if(n == 0){
	        return 1;
	    }
	    return dp[i][j][n] = helper(key,i,j,n-1,dp)+helper(key,i-1,j,n-1,dp)+helper(key,i+1,j,n-1,dp)+helper(key,i,j-1,n-1,dp)+helper(key,i,j+1,n-1,dp);
	}
	
	long long getCount(int n)
	{
		// Your code goes here
		vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(3, vector<long long>(n, -1)));
		int key[4][3] = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
		long long count = 0;
		for(int i = 0 ; i < 4 ; i++){
		    for(int j = 0 ; j < 3 ; j++){
		        if(key[i][j] == -1){
		            continue;
		        }
		        count += helper(key,i,j,n-1,dp);
		    }
		}
		return count;
		
	}
