// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    bool static comp(Item a1, Item a2){
       double p1 = (double)a1.value/(double)a1.weight;
       double p2 = (double)a2.value/(double)a2.weight;
       return p1> p2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        sort(arr,arr+n,comp);
        
       
        double profit = 0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i].weight <= W){
                profit += arr[i].value;
                W -= arr[i].weight;
                
            }
            else{
                profit += W * ((double)arr[i].value/(double)arr[i].weight);
                break;
            }
        }
        return profit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
