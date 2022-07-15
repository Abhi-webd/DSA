int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    int ans=0;
     int n=nums.size();
     if(n==1) return 1;
     vector<int> temp;
     temp.push_back(nums[0]);
     for(int i=1;i<n;i++){
         if(nums[i]!=nums[i-1]) temp.push_back(nums[i]);
     }

for(int i=1;i<temp.size()-1;i++){
         if(temp[i]>temp[i-1] and temp[i]>temp[i+1]) ans++;
         else if(temp[i]<temp[i-1] and temp[i]<temp[i+1]) ans++;
     }
     return ans+2;
		}
