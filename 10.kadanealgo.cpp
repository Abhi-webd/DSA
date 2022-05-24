class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n =  nums.size();
        if(n == 1){
            return nums[0];
        }
        int currs = 0;
        int maxs = INT_MIN;
        
        for(int i = 0 ; i < n ; i++){
            currs += nums[i];
            if(currs > maxs){
                maxs = currs;
            }
            if(currs < 0){
                currs = 0;
            }
        }
        return maxs;
    }
};
