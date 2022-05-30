#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr , int s ,int mid , int e){
    int i = s;
    int j = mid + 1;
    vector<int> a;
    int count = 0;
    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            a.push_back(arr[i]);
            i++;
        }
        else{
            count += (mid-i)+1;
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
    return count;

}


int invcnt(vector<int> &arr , int s , int e){
    if(s >= e){
        return 0;
    }
    
    int mid = (s+e)/2;
    int c1 = invcnt(arr,s,mid);
    int c2 = invcnt(arr,mid+1,e);
    int ci = merge(arr,s,mid,e);
    return c1+c2+ci;
}

int main()
{
    vector<int> arr{0,5,2,3,1};

    int s = 0;
    int e = arr.size() - 1;

    cout<<invcnt(arr,s,e);
    return 0;
}
