#include <bits/stdc++.h>
using namespace std;

float squareRoot(int n ,int p){
    int s = 0 ;
    int e = n;
    float ans = 0;

    while(s <= e){
        int mid = s + (e-s)/2;

        if(mid*mid == n){
            ans = mid;
            return ans;
        }
        else if(mid*mid < n){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
    }
    float start = 0.1;
    for(int i = 1 ; i <= p ; i++){
        while(ans*ans <= n){
            ans += start;
        }
        ans = ans-start;
        start *= 0.1;
    }
    return ans;
}

int main()
{
    int n,p;
    cin>>n>>p;

    cout<<squareRoot(n,p)<<endl;
    return 0;
}
