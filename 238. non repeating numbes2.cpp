bool set(int a , int pos){
    return ( (a & (1 << pos)) != 0);
}

    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> ans;
        int xorsum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            xorsum = xorsum^nums[i];
        }
        
        int pos = 0;
        int setBit = 0;
        int xors = xorsum;
        while(setBit != 1){
            setBit = xorsum & 1;
            pos++;
            xorsum = xorsum >> 1;
        }
        int newxor = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(set(nums[i],pos-1)){
                newxor = newxor^nums[i];
            }
        }
        int num1 = newxor;
        int num2 = newxor^xors;
        if(num1 < num2){
            ans.push_back(num1);
            ans.push_back(num2);
        }
        else{
            ans.push_back(num2);
            ans.push_back(num1);
        }
        return ans;
    }
