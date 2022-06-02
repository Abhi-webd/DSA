#include <bits/stdc++.h>
using namespace std;

// void subsets(string s ,string temp,int i, set<string> &v){
//     if(temp.size() <= s.size()){
//         v.insert(temp);
//     }
//     if(i >= s.size()){
//         return;
//     }
//     subsets(s,temp+s[i],i+1,v);
//     subsets(s,temp,i+1,v);
    
// }

void subsets(string s ,string temp, vector<string> &v){
    if(s.empty()){
        v.push_back(temp);
        return;
    }
    subsets(s.substr(1),temp+s[0],v);
    subsets(s.substr(1),temp,v);
    
}

int main()
{
    string s;
    cin>>s;
    string temp = "";

    vector<string> v;
    subsets(s,temp,v);
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}
