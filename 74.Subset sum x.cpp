#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> arr, int n , int i , int sum){
    if(i == n ){
        if(sum == 0){
            return 1;
        }
        return 0;
    }

    return countSubsets(arr,n,i+1,sum-arr[i]) + countSubsets(arr,n,i+1,sum);
}

int main()
{
    vector<int> arr{1,2,3,4,5};
    int x = 6;
    int i = 0;
    int n = arr.size();

    cout << countSubsets(arr,n,i,x);
    return 0;
}
