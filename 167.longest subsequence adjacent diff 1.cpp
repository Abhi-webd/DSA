// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int arr[])
    {
        // code here
        vector<int> a(N,1);
    
        
        for(int i = 1 ; i < N ; i++){
            for(int j = 0 ; j < i ; j++){
                if(abs(arr[j]-arr[i])==1){
                   int temp = a[j]+1;
                //   cout<<temp<<" ";
                   if(temp >  a[i]){
                       a[i] = temp;
                   }
                }
            }
        }
        int ans = 0;
        for(auto i : a){
            // cout<<i<<" ";
            if(i > ans){
                ans = i;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends
