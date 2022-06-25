#include <bits/stdc++.h>
using namespace std;

int getMinCost(vector<int> stones){
    int n =  stones.size();
    vector<int> dp(n,0);

    dp[0] =  0;
    dp[1] = abs(stones[1] - stones[0]);

    for(int i = 2 ; i < n ; i++){
        int val1 = dp[i-2] + abs(stones[i-2]-stones[i]);
        int val2 = dp[i-1] + abs(stones[i-1]-stones[i]);
        dp[i] = min(val1,val2);
    }
    return dp[n-1];
}

int main()
{
    int n;
    cin>>n;

    vector<int> stones(n);
    for(int i = 0 ; i < n ; i++){
        cin>>stones[i];
    }

    cout<<getMinCost(stones)<<endl;
    return 0;
}
