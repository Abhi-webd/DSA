// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    long long int ans = 0;
    sort(arr,arr+n);
    
    int i = 0;
    int j = n-1;
    while( i < j){
        ans += arr[j] - arr[i];
        i++;
        if(j > i){
            ans+= arr[j] - arr[i];
            j--;
        }
    }
    ans += arr[j] - arr[0];
    return ans;
    
}
