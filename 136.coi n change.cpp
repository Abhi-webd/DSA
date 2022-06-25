#include <bits/stdc++.h>
using namespace std;


//bottom up approach
int minNumberofCoins(int n, vector<int> denoms){
    int coins[n+1] = {0};
    coins[0] = 0;

    for(int i = 1 ; i <= n ; i++){
        coins[i] = INT_MAX;
        for(auto j:denoms){
            if(i-j >= 0 && coins[i-j] != INT_MAX){
                coins[i] = min(coins[i-j]+1,coins[i]);
            }
        }
    }
    return coins[n] == INT_MAX ? -1 : coins[n];

}

int main()
{
    vector<int> denoms = {1,3,7,10};
    cout<<minNumberofCoins(15,denoms);
    return 0;
}
