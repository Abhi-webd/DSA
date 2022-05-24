#include <bits/stdc++.h>
using namespace std;

int trappedWater(vector<int> &a){
    int n = a.size();
    vector<int> left;
    vector<int> right;

    for(int i = 0 ; i < n ; i++){
        if(left.size() == 0 ){
            left.push_back(a[i]);
        }
        else if(a[i] > left[i-1]){
            left.push_back(a[i]);
        }
        else{
            left.push_back(left[i-1]);
        }
    }

    for(int i = n-1 ; i >= 0 ; i--){
        if(right.size() == 0 ){
            right.push_back(a[i]);
        }
        else if(a[i] > right[n-2-i]){
            right.push_back(a[i]);
        }
        else{
            right.push_back(right[n-2-i]);
        }
    }

    reverse(right.begin(),right.end());
    int sum = 0;
    for(int i = 1 ; i < n-1 ; i++){
        int s = min(left[i],right[i]) - a[i];
        cout<<s<<" ";
        sum += s;
    }
    return sum;
}

int main()
{
    vector<int> water{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappedWater(water)<<endl;
    return 0;
}