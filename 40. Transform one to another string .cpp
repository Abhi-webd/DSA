// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	int n = A.length();
    	int l = B.length();
    	
    	if( n != l){
    	    return -1;
    	}
    	int count[256] = {0};
    // 	 memset(count, 0, sizeof(count));
    	for(int i = 0  ; i < n ; i++){
    	    count[A[i]]++;
    	}
    	for(int i = 0 ; i < n ; i++){
    	    count[B[i]]--;
    	}
    	for(int i = 0 ; i < 256 ; i++){
    	    if(count[i] > 0){
    	        return  -1;
    	    }
    	}
    	int res = 0;
    	for(int i = n-1 , j = n-1 ; i >=0 ;){
    	    while(i >=0 && A[i] != B[j]){
    	        res++;
    	        i--;
    	    }
    	    if(i>=0){
    	        i--;
    	        j--;
    	    }
    	}
    	return res;
    	
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends
