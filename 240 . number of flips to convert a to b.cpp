int countBitsFlip(int a, int b){
        
        // Your logic here
        int m = max(a,b);
        int count = 0;
        int get = 1;
        while(m){
            if((a & get) != (b & get)){
                count++;
            }
            a = a >> 1;
            b = b>>1;
            m =  m>>1;
        }
        return count;
        
    }
