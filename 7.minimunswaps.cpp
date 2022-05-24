#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &a){
    //knw actual positions storing current indexes
    int n = a.size();
    pair<int,int> ap[n];
    for(int i = 0 ; i < n ;i++){
        ap[i].first = a[i];
        ap[i].second = i;
    }
    int ans = 0;
    sort(ap,ap+n);
    vector<bool> visited(n,false);
    for(int i = 0 ; i < n ; i++){
        //element is visited or element in right position
        int oldp = ap[i].second;
        if(visited[i] == true || oldp == i){
            continue;
        }


        //visiting element for the first time
        //hopinf from one element to another until we reach original one
        // and we will counbt number of elements visitied

        int node = i;
        int cycle = 0 ;
        
        while(!visited[node]){
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle += 1;
        }
        ans += cycle -1;
    }
    return ans;

}

int main()
{
    vector<int> a{5,4,3,2,1};
    cout<<minSwaps(a)<<endl;
    return 0;
}