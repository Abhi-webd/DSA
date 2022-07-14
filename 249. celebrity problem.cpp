 int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        map<int,int> m;
        for(int i = 0 ; i < n ; i++){
            m[i] = 0;
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(M[i][j] > 0){
                    m[i]++;
                }
            }
        }
        bool flag =  false;
        int count = 0;
        for(auto i : m ){
            if(i.second > 0){
                flag = true;
            }
            if(i.second == 0){
                count++;
            }
            
        }
        if(!flag || count > 1){
            return -1;
        }
        
        for(auto i : m){
            if(i.second == 0){
                return i.first;
            }
        }
        return -1;
    }
