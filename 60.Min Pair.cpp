#include <bits/stdc++.h>
using namespace std;

void minPair(vector<int> a1, vector<int> a2){
    sort(a2.begin(),a2.end());

    pair<int,int> p;
    int min = INT_MAX;
    for(int i = 0 ; i < a1.size(); i++){
        int k = lower_bound(a2.begin(),a2.end(),a1[i]) - a2.begin();
        cout<<a1[i]<<" "<<k<<endl;
        int temp = abs(a2[k] - a1[i]);
        if(min > temp){
            min = temp;
            p.first = a1[i];
            p.second = a2[k];
        }
        if(k-1>=0 || k == a2.size()){
            temp = abs(a2[k-1] - a1[i]);
            if(min > temp){
                min = temp;
                p.first = a1[i];
                p.second = a2[k-1];
            }
        }
    }
    cout<<p.first<<" "<<p.second;

}

int main()
{
    vector<int> a1 = {-1,5,10,20,200};
    vector<int> a2 = {21,134,135,15,17};
    minPair(a1,a2);
    return 0;
}
