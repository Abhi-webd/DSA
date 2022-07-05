class Solution {
public:
   
    
    bool canJump(vector<int>& nums) {
         int distance_max = nums[0];
        int i = 0;
        for(auto j_pot : nums){
            if(distance_max < i) break;
            distance_max = max(distance_max, j_pot+i);
            i++;
        }
        return nums.size() <= distance_max + 1;
    }
};
