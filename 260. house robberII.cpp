class Solution {
public:
    int helper(vector<int> &a , int i, int j){
        int pre = 0;
        int cur = 0;
        
        for(int k = i; k <= j; k++){
            int temp = max(pre+a[k],cur);
            pre = cur;
            cur = temp;
            cout<<cur<<" "<<endl;
        }
        return cur;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 1){
            return nums[0];
        }
        return max(helper(nums,0,n-2) , helper(nums,1,n-1));
    }
};
