#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int> &a, int s , int e){
    int pivot = a[e];
    int i = s-1;

    for(int j = s ; j <e ; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}

void quicksort(vector<int> &a, int s, int e){
    int j;
    if(s < e){
        j = pivot(a,s,e);
        quicksort(a,s,j-1);
        quicksort(a,j+1,e);
    }
}


int main()
{
    vector<int> arr{10,5,2,0,7,6,4};
    int n = arr.size();
    quicksort(arr,0,n-1);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}
