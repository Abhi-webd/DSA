#include <bits/stdc++.h>
using namespace std;

int lowerb(vector<int> arr, int key){
    int s = 0;
    int e = arr.size() - 1;

    int curr = -1;
    while(s <=e){
        int mid = s + (e-s)/2;
        // cout<<arr[mid]<<" ";
        if(arr[mid] ==  key){
            curr = mid;
            e = mid - 1;
        }
        else if(arr[mid] > key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return curr;
}

int upperb(vector<int> arr, int key){
    int s = 0;
    int e = arr.size() - 1;

    int curr = -1;
    while(s <=e){
        int mid = s + (e-s)/2;
        // cout<<arr[mid]<<" ";
        if(arr[mid] ==  key){
            curr = mid;
            s = mid + 1;
        }
        else if(arr[mid] > key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return curr;
}

int main()
{
    vector<int> arr = {0,1,1,2,3,3,3,3,4,5,5,5,10};
    int n = arr.size();

    int l = lowerb(arr,6);
    int j = upperb(arr,6);
    cout<<j-l+1<<endl;
    return 0;
}
