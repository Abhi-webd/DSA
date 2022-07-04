class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        
        for(int i =  1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i]-nums[j] > 0){
                    int temp = 1+ dp[j];
                    if(temp > dp[i]){
                        dp[i] = temp;
                    }
                }
            }
        }
        int ans = 0;
        for(auto i : dp){
            if(i > ans) ans= i;
        }
        return ans;
    }
};
