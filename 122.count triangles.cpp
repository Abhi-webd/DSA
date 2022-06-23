#include <bits/stdc++.h>
using namespace std;

int countTriangles(vector<pair<int,int>> points){
    unordered_map<int,int> xp;
    unordered_map<int,int> yp;

    for(auto i:points){
        xp[i.first]++;
        yp[i.second]++;
    }

    int ans = 0;
    for(auto p:points){
        int x = p.first;
        int y = p.second;

        int x_same = xp[x];
        int y_same = yp[y];
        ans+= (x_same-1)*(y_same-1);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> points;

    for(int i = 0 ; i < n ; i++){
        int x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }

    cout<<countTriangles(points);
    return 0;
}
