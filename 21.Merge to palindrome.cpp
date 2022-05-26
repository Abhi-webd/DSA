#include <bits/stdc++.h>
using namespace std;

int findMinOps(int arr[] , int n){
  int s = 0;
  int e =  n-1;
  int count = 0;
  while(s<=e){
    if(arr[s] == arr[e]){
      s++;
      e--;
    }
    else if(arr[s] > arr[e]){
      e--;
      arr[e] = arr[e] + arr[e+1];
      count++;
    }
    else{
      s++;
      arr[s] += arr[s-1];
      count++;
    } 
  }
  return count;
}



int main()
{
    int arr[] = {1, 4, 5, 9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Count of minimum operations is "
         <<  findMinOps(arr, n) << endl;
    return 0;
}
