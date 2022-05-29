// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n = s.length();
	    if(n == 0 || n== 1){
	        return n;
	    }
	    bool flag = true;
	    for(int i = 0 ; i < n-1 ; i++){
	        if(s[i] != s[i+1]){
	            flag = false;
	        }
	    }
	    if(flag == true){
	        return n-1;
	    }
	    int i = 0;
	    int j = 0;
	    if(n % 2 == 0){
	        j = (n/2);
	        i = 0;
	    }
	    else{
	        j = (n/2)+1;
	        i = 0;
	    }
	    int count = 0;
	    while(j <n && i < (n/2)){
	       // cout<<j<<" "<<i<<endl;
	        if(s[i] == s[j]){
	            count++;
	            j++;
	            i++;
	        }
	        else{
	            count = 0;
	            if(i == 0){
	                j++;
	            }
	            else{
	                i = 0;
	            }
	            
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
