// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
int findCloset(vector<int> arr, int s, int e, int x){
    if(x < arr[s]){
        return s;
    }
    if(x >= arr[e]){
        return e;
    }
    
    int mid = (s+e)/2;
    if(arr[mid] <= x && arr[mid+1] > x){
        return mid;
    }
    
    if(arr[mid] < x){
        return findCloset(arr,mid+1,e,x);
    }
    return findCloset(arr,s,mid-1,x);
}
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector<int> ans;
        int l = findCloset(arr,0,n-1,x);
        int r = l+1;
        
        if(arr[l] == x){
            l--;
        }
        // cout<<l<<" "<<r<<endl;
        int count = 0;
        while(l >=0 && r < n && count < k){
            if(x - arr[l] <arr[r] - x){
                ans.push_back(arr[l--]);
                count++;
            }
            else{
                ans.push_back(arr[r++]);
                count++;
            }
        }
        
        while(l >=0 && count < k){
            ans.push_back(arr[l--]);
            count++;
        }
        
        while(r < n && count < k){
            ans.push_back(arr[r++]);
            count++;
        }
        return ans;
        cout<<l;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
