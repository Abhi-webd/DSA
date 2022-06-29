// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if(D*9 < S){
            return "-1";
        }
        vector<int> n(D,0);
        n[0] =  1;
        int sum = 1;
        int i = D-1;
        while(sum != S && i>=0){
            if(S - sum > 9){
                n[i] += 9;
                i--;
                sum += 9;
            }
            else{
                n[i] += S-sum;
                break;
            }
        }
        int ans = 0;
        for(int i = 0 ;i < D ; i++ ){
            ans = ans*10 + n[i];
        }
        return to_string(ans);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends
