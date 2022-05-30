#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr , int s ,int mid , int e){
    int i = s;
    int j = mid + 1;
    vector<int> a;

    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            a.push_back(arr[i]);
            i++;
        }
        else{
            a.push_back(arr[j]);
            j++;
        }
    }
    for( ; i <= mid ; i++){
        a.push_back(arr[i]);
    }
    for( ; j <= e ; j++){
        a.push_back(arr[j]);
    }

    int k = 0;
    for( i = s ; i <= e ; i++){
        arr[i] = a[k];
        k++;
    }
    cout<<endl;
    return;

}


void mergesort(vector<int> &arr , int s , int e){
    if(s >= e){
        return;
    }
    
    int mid = (s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    return merge(arr,s,mid,e);
}

int main()
{
    vector<int> arr{0,5,2,3,1};

    int s = 0;
    int e = arr.size() - 1;

    mergesort(arr,s,e);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}
