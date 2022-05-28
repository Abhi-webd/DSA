class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2){
            return s;
        }
        int ans = 0;
        int start=0;
        int left,right;
        for(int i = 0 ; i < n ; i++){
            left = i-1;
            right = i+1;
            while(left >= 0 && s[i] == s[left]){
                left--;
            }
            while(right < n && s[i] == s[right]){
                right++;
            }
            while(left >= 0 && right < n && s[left] == s[right]){
                left --;
                right++;
            }
            int len = right-left - 1;
            cout<<len<<" ";
            if(ans < len){
                ans = len;
                start = left+1;
            }
        }
        string final = s.substr(start,ans);
        return final;
    }
};
