#include <bits/stdc++.h>
using namespace std;

//recursion 
int countWays(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    
    return countWays(n-1) + countWays(n-2) + countWays(n-3);
}

//dp top down approach
int countways(int n, int dp[]){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    return dp[n] = countways(n-1,dp) + countways(n-2,dp) + countways(n-3,dp);
}

//dp bottom up approach
int countBottomUp(int n){
    int dp[n+1] = {0};
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        int k = 1;
        while(i-k >=0 && k <=3){
            dp[i] += dp[i-k];
            k++;
        }
    }
    return dp[n];
}

//dp more optimise bottom up
int countBottomUpOptimise(int n){
    int dp[n+1] = {0};
    dp[0] = dp[1] = 1;
    for(int i = 2 ; i <= 3 ; i++){
        dp[i] = 2*dp[i-1];
    }
    for(int i = 4 ; i <= n ; i++){
        dp[i] = 2*dp[i-1] - dp[i - 4];
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<countWays(n)<<endl;
    int dp[n+1] = {0};
    cout<<countways(n,dp)<<endl;
    cout<<countBottomUp(n)<<endl;
    cout<<countBottomUpOptimise(n)<<endl;
    return 0;
}  
