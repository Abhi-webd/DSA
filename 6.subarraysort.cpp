//find smallest and largest element which is out of place and
//then find the correct position for them
//for smallest from left for largest from right
#include <bits/stdc++.h>
using namespace std;

pair<int,int> subarraySort(vector<int> &a){
    pair<int,int> p;
    int min = INT_MAX;
    int max = INT_MIN;
    int n =  a.size();
    for(int i = 0 ; i < n; i++ ){
        if( i == 0){
            if(a[i] > a[i+1]){
                if(a[i] < min){
                    min = a[i];
                }
                if(a[i] > max){
                    max = a[i];
                }
            }
        }
        else if( i == n-1){
            if(a[i] < a[i-1]){
                if(a[i] < min){
                    min = a[i];
                }
                if(a[i] > max){
                    max = a[i];
                }
            }
        }
        else{
            if(a[i] < a[i-1] || a[i] > a[i+1]){
                if(a[i] < min){
                    min = a[i];
                }
                if(a[i] > max){
                    max = a[i];
                }
            }
        }
    }
    cout<<max<<" "<<min<<endl;
    for(int i = 0 ; i < n ; i++){
        if(a[i] > min){
            p.first = i;
            break;
        }
    }
    for(int i = n-1 ; i >= 0 ; i--){
        if(a[i] < max){
            p.second = i;
            break;
        }
    }
    return p;
}

int main()
{
    vector<int> a = {2,1,3,4,5,8,6,7,9,11,10};
    auto p = subarraySort(a);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}