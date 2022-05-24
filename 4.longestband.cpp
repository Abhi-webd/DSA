#include <bits/stdc++.h>
using namespace std;

int longestBand(vector<int> &a){
    unordered_set<int> s;
    int count = 0;
    int n = a.size();
    for(int i = 0 ; i < n ; i++){
        s.insert(a[i]);
    }

    for(int i = 0 ; i < n ; i ++){
        int x = a[i] - 1;
        if(s.find(x) == s.end()){
            int c = 1;
            int y = a[i] + 1;
            while(s.find(y) != s.end()){
                c++;
                y++;
            }
            cout<<c<<" ";
            if(c > count){
                count = c;
            }
        }
    }
    cout<<"\n";
    return count;
}

int main()
{
    vector<int> a{1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<longestBand(a);
    return 0;
}