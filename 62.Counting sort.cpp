// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 // } Driver Code Ends
//User function Template for C

//Function to arrange all letters of a string in lexicographical 
//order using Counting Sort.
char* countSort(char arr[]){
    
    //Your code here
    int a[256] = {0};
    for(int i = 0 ; i < strlen(arr) ; i++){
        a[arr[i]]++;
    }
    int k = 0;
    for(int i = 0 ; i < 256 ; i++){
        while(a[i] > 0){
            arr[k] = i;
            a[i]--;
            k++;
        }
    }
    return arr;
    
    
}

// { Driver Code Starts.

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		char str[n+1];
		scanf("%s", str);
		printf("%s\n", countSort(str));

	}
	return 0;

}  // } Driver Code Ends
