#include <bits/stdc++.h>
using namespace std;

int sparseSearch(string a[], int n, string key){
    int s = 0 ;
    int e = n-1;
    while(s <= e){
        int mid = (s+e)/2;
        int l = mid-1;
        int r = mid + 1;
        if(a[mid] == ""){
            while(1){
                if( l < s && r > e){
                    return -1;
                }
                else if(a[l] != "" and l>=s){
                    mid = l;
                    break;
                }
                else if(a[r] != "" and r<=e){
                    mid = r;
                    break;
                }
                l--;
                r++;
            }
        }
        if(a[mid] == key){
            
            return mid;
        }
        else if(a[mid] > key){
            e = mid-1;
        }
        else{
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{
    string arr[] = {"ai","","","bat","","","car","cat","","","dog","e"};
    int n = 12;
    cout<<sparseSearch(arr,n,"ai")<<endl;
    return 0;
}
