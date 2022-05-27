#include <bits/stdc++.h>
using namespace std;

bool isSubset(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    int i,j;
    i = n1-1;
    j = n2-1;

    while(i >=0 && j >=0){
        if(s1[i] == s2[j]){
            i--;
            j--;
        }
        else{
            i--;
        }
    }
    if(j == -1){
        return true;
    }
    return false;
}

int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<isSubset( s1, s2);
    return 0;
}
