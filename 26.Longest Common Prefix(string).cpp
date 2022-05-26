class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n =  strs.size();
        int i = 0;
        while(i < strs[0].size()&& strs[0][i] == strs[n-1][i]){
            i++;
        }
        if(strs[0][0] != strs[n-1][0]){
            return "";
        }
        
        return strs[0].substr(0,i);
    }
    
};
