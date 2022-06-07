// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> s;
        for(int i = 0 ; i < S.size() ; i++){
            if(S[i] >= '0' && S[i] <= '9'){
                // cout<<S[i]<<" "<<S[i]-'0'<<endl;
                s.push(S[i]-'0');
            }
            else{
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                if(S[i] == '+'){
                    int ans = temp1+temp2;
                    s.push(ans);
                }
                if(S[i] == '-'){
                    int ans = temp2-temp1;
                    s.push(ans);
                }
                if(S[i] == '*'){
                    int ans = temp1*temp2;
                    s.push(ans);
                }
                if(S[i] == '/'){
                    int ans = temp2/temp1;
                    s.push(ans);
                }
            }
        }
        return s.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
