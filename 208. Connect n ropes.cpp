long long minCost(long long arr[], long long n) {
        // Your code here
         if(n == 1)  return 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq (arr, arr+n);
        
        long long ans = 0;
        while(pq.size() > 1)
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            ans = ans + first + second;
            pq.push(first + second);
        }
        return ans;
    }
