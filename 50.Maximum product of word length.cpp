class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> word_int(n,0);
        vector<int> word_len(n,0);
        for(int i = 0 ; i < n ; i++){
            string s = words[i];
            int len = s.length();
            int w_int = 0;
            for(int j = 0 ; j < len ; j++){
                w_int |= 1 << (s[j] - 'a'); //bit maipulation hashmap using bit or bitset to reduce time
            }
            word_int[i] = w_int;
            word_len[i] = len;
        }
        int maxp = 0;
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                if((word_int[i] & word_int[j]) == 0){
                    maxp = max(maxp,word_len[i]*word_len[j]);
                }
            }
        }
        return maxp;
    }
};
