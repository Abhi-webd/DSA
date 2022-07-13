int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        // vector<vector<int> dp(N,vector<int> ());
        
        for(int i = N-2 ; i >= 0 ; i--){
            for(int j = 0 ; j < N ; j++){
                int left = 0;
                if(j-1 >= 0){
                    left = Matrix[i+1][j-1];
                }
                int mid = Matrix[i+1][j];
                int right = 0;
                if(j+1 < N){
                    right = Matrix[i+1][j+1];
                }
                int m = max(left,max(right,mid));
                Matrix[i][j] += m;
            }
        }
        int m = 0;
        for(int  i = 0 ; i < N ; i++){
            if(m < Matrix[0][i]){
                m = Matrix[0][i];
            }
        }
        return m;
    }
