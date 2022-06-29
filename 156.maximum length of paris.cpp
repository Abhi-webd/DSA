// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
static bool comp(val p1, val p2){
    return p1.first < p2.first;
}

bool comp2(int a, int b){
    return a < b;
}

int maxChainLen(struct val p[],int n)
{
//Your code here
sort(p,p+n,comp);
vector<int> mcl(n,1);

for(int i = 1 ; i < n ; i++){
    for(int j = 0 ; j < i ; j++ ){
        if(p[i].first > p[j].second && mcl[i] < mcl[j] + 1){
            mcl[i] = mcl[j] + 1;
        }
    }
}
int ans = *max_element(mcl.begin(),mcl.end(),comp2);
return ans;
}
