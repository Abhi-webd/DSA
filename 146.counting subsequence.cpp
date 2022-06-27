#include <bits/stdc++.h>
using namespace std;

int count(string a, string b, int m , int n){
    if((m == -1 && n == -1) || n == -1){
        return 1;
    }
    if(m == -1){
        return 0;
    }

    if(a[m] == b[n]){
        return count(a,b,m-1,n-1) + count(a,b,m-1,n);
    }
    return count(a,b,m-1,n);
 
    
}

int countdp(string a, string b, int m , int n,vector<vector<int>> &dp){
    if(m == -1 && n == -1 || n == -1){
        return 1;
    }
    if(m == -1){
        return 0;
    }

    if(dp[m][n] != 0){
        return dp[m][n];
    }

    if(a[m] == a[n]){
        return dp[m][n] = countdp(a,b,m-1,n-1,dp) + countdp(a,b,m-1,n,dp);
        
    }
    return dp[m][n] = countdp(a,b,m-1,n,dp);

}

int countBU(string a, string b){
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));

    for(int i =  0 ; i <=m ; i++){
        dp[i][0] = 1;
    }

    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] =  dp[i-1][j];
            }
        }
    }
    for(auto i : dp){
        for(auto j : i ){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return dp[m][n];
}


int main()
{
    string a = "ABBCECDGCC";
    string b = "ABC";
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
    cout<<countBU(a,b);
    return 0;
}
