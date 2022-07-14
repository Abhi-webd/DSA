 int countSetBits(int n)
    {
        // Your logic here
         int count=0;
        while(n>=1){
            if(n==1){
                count++;break;
            }
            int k = log2(n);
            int power = pow(2,k);
            count+=(n+1)+(k-2)*(power/2);
            n-=power;
        }
        return count;
    }
