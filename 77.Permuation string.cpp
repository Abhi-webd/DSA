// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	 
	 
	 void permutation(string s, int f , int l , vector<string> &v){
	      if(f == l){
	         if(count(v.begin(),v.end(),s) == 0){ 
             v.push_back(s);}
             return ;
            }

           for(int i = f; i <= l ; i++){
              swap(s[f],s[i]);
              permutation(s,f+1,l,v);
              swap(s[f],s[i]); //backtracking
	        }
	 }	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    int n = S.size();
		    vector<string> v;
		    permutation(S,0,n-1,v);
		    sort(v.begin(),v.end());
		    return v;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
