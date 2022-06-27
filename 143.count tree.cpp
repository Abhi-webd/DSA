#include  <bits/stdc++.h>
using namespace std;

int countBST(int n){
    if(n == 0 ||  n == 1){
        return 1;
    }

    int ans = 0;
    for(int i = 1 ; i <=n ; i++ ){
        ans += countBST(i-1)*countBST(n-i);
    }
    return ans;
}

int countBSTTopdwon(int n, vector<int> &dp){
    if(n == 0 ||  n == 1){
        return 1;
    }

    if(dp[n] != 0){
        return dp[n];
    }

    int ans = 0;
    for(int i = 1 ; i <=n ; i++ ){
        ans += countBSTTopdwon(i-1,dp)*countBSTTopdwon(n-i,dp);
    }
    return dp[n]=ans;
}

int countBSTBottomup(int n){
    vector<int> dp(n+1,0);
    dp[0] = dp[1] = 1;

    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j <= i ;  j++){
            dp[i] += dp[j-1]*dp[i-j]; 
        }
    }

    return dp[n];
}

int main()
{
    int n = 5;
    vector<int> dp(n+1,0);
    cout<<countBSTBottomup(n)<<endl;
    return 0;
}
