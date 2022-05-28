class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> m ;
        int i = 0; 
        int j = 0;
        int maxc = 0;
        int ans = 0;
        while( j < s.length()){
            m[s[j]]++;
            maxc = max(maxc,m[s[j]]);
            if((j-i+1) - maxc > k){
                m[s[i]]--;
                i++;
            }
            ans  =  max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};
