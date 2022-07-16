int mod = 1e9+7;
    long int disarrange(int N){
        // code here
        if(N  == 1 || N == 2){
            return N-1;
        }
        
        long int a = 0;
        long int b = 1;
        
        
        for(int i = 3 ; i<=N ; i++){
            long cur = ((i-1)*((a + b)%mod))%mod;
            a = b;
            b = cur;
        }
        return b;
    }
