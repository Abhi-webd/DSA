class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int x = nums.size();
        int n = nums.size() -1;
        int mid = i + (n-i)/2;
        
        int last = nums[n];
        while(i < n){
            if(nums[mid] > last){
                i = mid+1;
            }
            else if(nums[mid] < last){
                n = mid - 1;
                
            }
            else{
                break;
            }
            mid = i + (n-i)/2;
        }
        if(mid+1<x){
            if(nums[mid] < nums[mid+1]){
                return nums[mid];
            }
            else{
                return nums[mid+1];
            }
        }
        return nums[mid];
    }
};
