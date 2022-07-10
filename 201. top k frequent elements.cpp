class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto i:nums){
            if(m[i] > 0){
                m[i]++;
            }
            else{
                m[i] = 1;
            }
        }
        vector<pair<int,int>> v;
        for(auto &i:m){
            v.push_back(i);
        }
        
        sort(v.begin(),v.end(),cmp);
        vector<int> res;
        for(int i = 0 ; i <k ; i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
            res.push_back(v[i].first);
        }
        return res;
    }
};
