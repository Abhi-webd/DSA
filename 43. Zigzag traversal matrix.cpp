// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> ans;
		int k;
		int j = 0;
		for( int i = 0 ; i < n ; i++){
		    j = 0;
		    k = i;
		    while( j < n && k >=0){
		        ans.push_back(A[j][k]);
		        j++;
		        k--;
		    }
		}
		for(int i = 1 ; i < n  ; i++){
		    j = i;
		    k = n-1;
		    while(j < n && k >=0){
		        ans.push_back(A[j][k]);
		        j++;
		        k--;
		    }
		}
		return ans;
	}

};

// { Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}
  // } Driver Code Ends
