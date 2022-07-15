vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int> q;
        vector<int> ans(n,0);
        q.push(arr[n-1]);
        ans[n-1] = -1;
        for(int i = n-2 ; i >=0 ; i--){
            while(!q.empty() && arr[i] <= q.top()){
                q.pop();
            }
            if(!q.empty() && arr[i] > q.top()){
                ans[i] = q.top();
                q.push(arr[i]);
            }
            if(q.empty()){
                ans[i] = -1;
                q.push(arr[i]);
            }
        }
        return ans;
    } 
