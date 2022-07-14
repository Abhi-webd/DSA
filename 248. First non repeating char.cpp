string FirstNonRepeating(string A){
		    // Code here
		    map<char,int> m;
		    queue<char> q;
		    
		    int n = A.size();
		    m[A[0]] = 1;
		    q.push(A[0]);
		    for(int i = 1 ; i < n ; i++){
		        m[A[i]]++;
		        if(m[A[i]] == 1){
		            q.push(A[i]);
		        }
		        while(!q.empty() && m[q.front()] > 1){
		            q.pop();
		        }
		        if(q.empty()){
		            A[i] = '#';
		        }
		        else{
		            A[i] = q.front();
		        }
		        
		    }
		    return A;
		}
