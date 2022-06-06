// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void findcombinations(int i,vector<int> A, int tar, vector<vector<int>> &ans, vector<int> &curr){
        if(i == A.size()){
            if(tar == 0){
                // sort(curr.begin(),curr.end());
                // if(count(ans.begin(),ans.end(),curr) == 0){
                //     ans.push_back(curr);
                // }
                ans.push_back(curr);
            }
            return;
        }
        
        if(A[i] <= tar){
            curr.push_back(A[i]);
            findcombinations(i,A,tar-A[i],ans,curr);
            curr.pop_back();
        }
        findcombinations(i+1,A,tar,ans,curr);
        
    }
    
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        auto ip = std::unique(A.begin(), A.begin() + A.size());
        A.resize(std::distance(A.begin(), ip));
        vector<vector<int>> ans;
        vector<int> curr;
        findcombinations(0,A,B,ans,curr);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends
