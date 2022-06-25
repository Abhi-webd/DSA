#include <bits/stdc++.h>
using namespace std;

static bool comp(vector<int> v1, vector<int> v2){
    return v1[2] < v2[2];
}

int boxStacking(vector<vector<int>> boxes){
    int n = boxes.size();
    sort(boxes.begin(),boxes.end(),comp);
    vector<int> dp(n,0);

    for(int  i = 0 ; i < n ; i++){
        dp[i] = boxes[i][2];
    }

    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(boxes[i][0] > boxes[j][0] && boxes[i][1] > boxes[j][1] && boxes[i][2] > boxes[j][2]){
                int current_height  =  boxes[i][2];
                if(dp[j] + current_height > dp[i]){
                    dp[i] = dp[j] + current_height;
                }
            }
        }
    }
    int max_height = 0;
    for(int i = 0 ; i < n ; i++){
        max_height = max(max_height,dp[i]);
    }
    return max_height;

}

int main()
{
    vector<vector<int>> boxes =  {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5},
    };
    int height = boxStacking(boxes);
    cout<<height;
    return 0;
}
