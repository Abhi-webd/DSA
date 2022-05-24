// time complexity of the rpoblem is O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> pairSum(vector<int> &a, int sum){

    unordered_set<int> s;
    vector<int> ans;

    for(int i = 0 ; i < a.size() ; i++){

        int diff = sum - a[i];
        if(s.find(diff) != s.end()){
            ans.push_back(diff);
            ans.push_back(a[i]);
            return ans;
        }
        s.insert(a[i]);
    }
    return {};
}

int main()
{
    vector<int> a{10,5,2,3,-6,9,11};
    int s = 4;

    auto p = pairSum(a,s);
    if(p.size() == 0){
        cout<<"No such pair present"<<endl;
    }
    else{
        cout<<p[0]<<" "<<p[1]<<endl;
    }
    return 0;
}