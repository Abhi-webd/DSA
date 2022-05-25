class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int a1[n];
        int a2[n];
        
        a1[0] = 1;
        for(int i = 1 ; i < n ; i++){
            a1[i] = a1[i-1]*nums[i-1];
        }
        
        a2[n-1] = 1;
        for(int i = n-2 ; i >= 0 ; i--){
            a2[i] = a2[i+1] * nums[i+1];
        }
        
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(a1[i]*a2[i]);
        }
        
        return ans;
    }
};
