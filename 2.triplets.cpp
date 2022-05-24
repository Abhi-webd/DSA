#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> &a, int s){
    int n =  a .size();
    sort(a.begin(),a.end());
    vector<vector<int>> ans;

    for(int i = 0 ; i < n-3 ; i++){
        int first = i;
        int second = i+1;
        int third = n-1;

        while(second < third){
            int sum = a[first] + a[second] + a[third];
            if(sum == s){
                ans.push_back({a[first],a[second],a[third]});
                second++;
                third--;
            }
            else if(sum > s){
                third -= 1;
            }
            else{
                second += 1;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> a{1,2,3,4,5,6,7,8,9,15};
    int s = 18;
    auto ans = triplets(a,s);
    for(auto i:ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}