#include <bits/stdc++.h>
using namespace std;

void Subsequence(string s, string o, vector<string> &v){
    //base case

    if(s.size() == 0){
        v.push_back(o);
        return;
    }
    //rec case
    char ch = s[0];
    string reduced_input = s.substr(1);
    Subsequence(reduced_input,o+ch,v);
    Subsequence(reduced_input,o,v);
}

bool comp(string s1, string s2){
    if(s1.length() == s2.length()){
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main()
{
    string s;
    cin>>s;

    vector<string> v;
    string output ="";
    Subsequence(s,output,v);
    sort(v.begin(),v.end(),comp);
    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}
