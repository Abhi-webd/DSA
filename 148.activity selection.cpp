// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool comp(pair<int,int> p1 , pair<int,int> p2){
        if(p1.second ==  p2.second){
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        pair<int,int> p[n];
        for(int i = 0 ; i < n ; i++){
            p[i].first = start[i];
            p[i].second =  end[i];
        }
        
        sort(p,p+n,comp);
        int ans = 1;
        int last  = p[0].second;
        for(int i = 1 ; i < n ; i++){
            if(p[i].first > last){
                ans++;
                last = p[i].second;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
