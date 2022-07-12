int helper( int sum  ,int idx, int arr[],vector<vector<int>> &dp){
    if(sum == 0 && idx >= 0){
        return 1;
    }
    if(idx < 0 || sum < 0){
        return false;
    }
    if(dp[idx][sum] != -1){
        return dp[idx][sum];
    }
    
    return dp[idx][sum] = helper(sum,idx-1,arr,dp) || helper(sum-arr[idx],idx-1,arr,dp);
}
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0 ; i < N ; i++){
            sum += arr[i];
        }
        if(sum % 2 !=0){
            return 0;
        }
        vector<vector<int>> dp( N, vector<int> (sum/2+1, -1));
        return helper(sum/2,N-1,arr,dp);
    }
