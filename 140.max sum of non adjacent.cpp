#include <bits/stdc++.h>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n+1,0);

    dp[0] = arr[0];
    dp[1] = max(dp[0],arr[1]);

    for(int i = 2 ; i < n ;i++){
        int val =  dp[i-2] + arr[i];
        dp[i] = max(dp[i-1],val);
    }
    return dp[n-1];

}

int main()
{
    vector<int> arr({6,10,12,7,9,14});
    cout<<maxSubsetSumNoAdjacent(arr);
    return 0;
}
