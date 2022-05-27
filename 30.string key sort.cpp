#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//to extract tokens or strings for comparsion

string extractKey(string str, int key){
    char * s = strtok((char*)str.c_str()," "); //this accepts char array so we converted string to char array 
    while(key > 1){
        s = strtok(NULL," ");
        key --;
    }
    return (string)s; 
}

//comparator for sorting numerically

int convertToInt(string s){
    int ans = 0;
    int p = 1;

    for(int i = s.size()-1; i>=0 ; i--){
        ans += (s[i] - '0')*p;
        p *= 10;
    }
    return ans;
}

bool ncomp(pair<string,string> s1, pair<string,string> s2){
    string key1,key2;
    key1 =  s1.second;
    key2 = s2.second;

    return convertToInt(key1) < convertToInt(key2);
}

//comparator for sorting lexographically
bool lcomp(pair<string,string> s1, pair<string,string> s2){
    string key1,key2;
    key1 =  s1.second;
    key2 = s2.second;

    return key1 < key2;
}

int main()
{
    int n;
    cin>>n;

    string temp;
    vector<string> v;
    for(int i = 0 ; i < n ; i++){
        getline(cin,temp);
        v.push_back(temp);
    }

    int key;
    string reversal,ordering;
    cin >> key >> reversal >> ordering;

    vector<pair<string,string>>vp;

    for(int i = 0  ; i < n ; i++){
        vp.push_back({v[i],extractKey(v[i],key)});
    }

    if(ordering == "numeric"){
        sort(vp.begin(),vp.end(),ncomp);
    }
    if(ordering == "lexo"){
        sort(vp.begin(),vp.end(),lcomp);
    }

    if(reversal == "true"){
        reverse(vp.begin(),vp.end());
    }

    for(int i = 0 ; i < n ; i++){
        cout<<vp[i].first<<endl;
    }

    return 0;
}
