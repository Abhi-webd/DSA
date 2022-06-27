 #include <bits/stdc++.h>
 using namespace std;

 int wines(int dp[][10], int prices[], int s, int e , int y){
    if(s > e){
        return 0;
    }

    if(dp[s][e] != 0){
        return dp[s][e];
    }

    int profit = max((prices[s]*y + wines(dp,prices,s+1,e,y+1)),(prices[e]*y + wines(dp,prices,s,e-1,y+1)));
    return dp[s][e] = profit;
 } 

 int wines_bottom_up(int prices[], int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int i =  n-1 ; i >=0 ; i--){
        for(int j = 0 ; j < n ; j++){
            if(i == j){
                dp[i][j] = n*prices[i];
            }
            else if(i < j){
                int year = n-(j-i);
                int pick_left = prices[i]*year + dp[i+1][j];
                int pick_right = prices[j]*year + dp[i][j-1];
                dp[i][j] = max(pick_left,pick_right);
            }
            cout<<endl;
        }
    }
    return dp[0][n-1];
 }

int main(){
    int a[] = {2,3,5,1,4};
    int n  = 5;
    int dp[10][10]   =  {0};
    cout<<wines_bottom_up(a,n)<<endl;
    return 0; 
}
