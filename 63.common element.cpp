// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> v1;
    int i1,i2;
    i1 = i2 = 0;
            
    while( i1<n1 && i2<n2){
        if(A[i1] > B[i2]){
            i2++;
        }
        else if(A[i1] < B[i2]){
            i1++;
        }
        else if(A[i1] == B[i2]){
            v1.push_back(A[i1]);
            i1++;
            i2++;
        }
    }

    i1 = i2 = 0;
    vector<int> v2;

    while( i1<v1.size() && i2<n3){
        if(v1[i1] > C[i2]){
            i2++;
        }
        else if(v1[i1] < C[i2]){
            i1++;
        }
        else if(v1[i1] == C[i2]){
            int c = count(v2.begin(),v2.end(),v1[i1]);
            if(c == 0){
            v2.push_back(v1[i1]);}
            i1++;
            i2++;
        }
    }
    
    // vector<int>::iterator ip;
  
    // ip = std::unique(v2.begin(), v2.begin() + v2.size());

    // v2.resize(std::distance(v2.begin(), ip));
  
    
    if(v2.empty()){
        v2.push_back(-1);
        return v2;
    }
    else{
        return v2;
    }

    
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends
