// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        // code here
        long long int curr = __gcd(L,B);
        unsigned long long int area = L*B;
        long long int ans = 0;
        // cout<<area<<" "<<curr<<endl;
        
        while(1){
            unsigned long long int carea = curr*curr;
            if(area % carea == 0){
                ans = area / carea;
                break;
            }
            else{
               curr--; 
            }
        }
        vector<long long int> a;
        a.push_back(ans);
        a.push_back(curr);
        return a;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends
