#include <bits/stdc++.h>
using namespace std;

string unique_substring(string s){
    int i = 0; 
    int j = 0;
    unordered_map<char,int> m;
    int windowl = 0;
    int maxwl = 0;
    int swindow = -1;

    while(j <s.length()){
        char ch = s[j];
        if(m.count(ch) && m[ch] >= i){
            i = m[ch] + 1;
            windowl = j - i;
        }

        m[ch] = j;
        windowl++;
        j++;
        if(maxwl < windowl){
            maxwl = windowl;
            swindow = i;
        }
    }
    return s.substr(swindow,maxwl);
}

int main()
{
    string s;
    cin>>s;

    cout<<unique_substring(s)<<endl;
    return 0;
}
