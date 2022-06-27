#include <bits/stdc++.h>
using namespace std;

int lcs(char *X, char *Y , int i , int j){
    if(i  == 0 || j == 0){
        return 0;
    }

    if(X[i-1] == Y[j-1]){
        return 1+ lcs(X,Y,i-1,j-1);
    }
    return max(lcs(X,Y,i-1,j),lcs(X,Y,i,j-1));
}

int lcstopDown(char *X, char *Y, int i, int j, vector<vector<int>> &dp){
    if(i == 0 || j == 0){
        return 0;
    }

    if(X[i-1] == Y[j-1]){
        return dp[i][j] =1+ lcstopDown(X,Y,i-1,j-1,dp);
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    return dp[i][j] = max(lcstopDown(X,Y,i-1,j,dp),lcstopDown(X,Y,i,j-1,dp));
}

int lcsbottomup(char* x, char* y , int m , int n){
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i = 1 ; i <= m ;  i++){
        for(int j = 1 ; j <= n ; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

   

    for(auto i : dp){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
     vector<char> result;
    int i = strlen(x);
    int j = strlen(y);
    while( i != 0 &&  j != 0){
        if(dp[i][j] == dp[i][j-1]){
            j--;
        }
        else if(dp[i-1][j] == dp[i][j]){
            i--;
        }
        else{
            result.push_back(x[i-1]);
            i--;
            j--;

        }
    }

    reverse(result.begin(),result.end());
        for(auto i :result){
            cout<<i<<" ";
        }
    return dp[m][n];
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
    cout<<lcsbottomup(X,Y,m,n);
    return 0;
}
