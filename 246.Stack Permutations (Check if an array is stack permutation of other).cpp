int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> s;
        int j = 0;
        for(int i = 0 ; i < N ; i++){
            s.push(A[i]);
            while(j < N && !s.empty() && s.top() == B[j] ){
                s.pop();
                j++;
            }
        }
        if(j == N){
            return 1;
        }
        return 0;
        
    }
