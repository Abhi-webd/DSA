int removals(vector<int>& a, int k){
        //Code here
        if(a.size() == 1 ){
            return 0;
        }
        
        vector<int> dp(a.size(),0);
        sort(a.begin(),a.end());
        for(int i = 1 ; i < a.size() ; i++){
            int count = 0;
            for(int j = 0 ; j <i ; j++){
                if(abs(a[i] - a[j]) <= k){
                    count++;
                }
            }
            dp[i] = count;
        }
        int m = 0;
        for(auto i : dp){
            // cout<<i<<" ";
            m = max(m,i);
        }
        
        return a.size() - m -1;
    }

int removals(vector<int>& a, int k){
        //Code here
        if(a.size() == 1 ){
            return 0;
        }
        sort(a.begin(),a.end());
        int s = 0;
        int ans = 1;
        int count = 1;
        for(int i = 1 ; i < a.size() ; i++){
            if((a[i] - a[s]) <= k){
                count++;
                if(ans < count){
                    ans = count;
                }
            }
            else{
                while(a[i]-a[s] > k){
                    s++;
                    count =  i-s+1;
                }
            }
        }
        
        return a.size()-ans;
    }
