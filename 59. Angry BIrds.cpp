#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, int freq, int bird){
    int i = 1;
    int n = a.size();
    int k = bird -1;
    int location = a[0];

    while(i < n){
        if(a[i] - location >= freq){
            location = a[i];
            i++;
            k--;
            if(k == 0){
                return true;
            }
        }
        else{
            i++;
        }
    }
    return false;
}

int main()
{
    int B = 3;
    vector<int> nests{1,2,4,8,9};
    sort(nests.begin(),nests.end());
    int N = nests.size();

    int s = 0;
    int e = N-1;
    int ans = 0;

    while(s <= e){
        int mid = (s+e)/2;
        bool canPlace = check(nests,mid,B);

        if(canPlace){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
