int maxLen(vector<int>&v, int n)
    {   
        // Your code here
       unordered_map<int,int> m;
        m[0]=-1;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
           sum=sum+v[i];
           if(m.find(sum) != m.end()){
              ans=max(ans,(i-m.find(sum)->second)); 
              continue;
           }
           m[sum]=i;
        }
        return ans;
    }
