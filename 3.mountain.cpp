#include <bits/stdc++.h>
using namespace std;

int height(vector<int> &a,int pos){
    int c = 1;

    int i = pos-1;
    
    while(a[i] < a[i+1] && i >=0){
        c++;
        i--;
    }

    i = pos+1;

    while(a[i] < a[i-1] && i < a.size()){
        c++;
        i++;
    }
    return c;
}

int mountain(vector<int> &a){
    // identifying peak;
    int count = 1;
    int n = a.size();

    for(int i = 1 ; i < n-2 ; i++){
        int j = i-1;
        int k = i+1;
        if(a[i] > a[j] && a[i] > a[k]){
            int c = height(a, i);
            if(c > count){
                count = c; 
            }
        }
    }
    return count;
}

int main()
{
    vector<int> a{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<mountain(a);
    return 0;
}