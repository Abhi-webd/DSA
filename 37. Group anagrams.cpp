class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size() == 1){
            ans.push_back(strs);
            return ans;
        }
        unordered_map<string,vector<string>> m;
        int n = strs.size();
        for(int i = 0  ; i < n ; i++){
            string temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].push_back(temp);
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
