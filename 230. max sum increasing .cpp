int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n);
	    for(int i = 0 ; i < n ; i++){
	        dp[i] = arr[i];
	    }
	    
	    
	    for(int i = 1 ; i < n ; i++){
	        for(int j = 0 ; j < i ; j++){
	            if(arr[i] - arr[j] > 0){
	                int temp = dp[j] + arr[i];
	                if(temp > dp[i]){
	                    dp[i] =  temp;
	                }
	            }
	        }
	    }
	    int m = 0;
	    for(auto i : dp){
	       m = max(i,m);
	    }
	    return m;
	}  
