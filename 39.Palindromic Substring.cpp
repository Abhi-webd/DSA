class Solution {
public:
    int countSubstrings(string s) {
       vector<string> a;
        int n = s.size();
        if(n < 2){
            return 1;
        }
        int ans = 0;
        int start=0;
        int left,right;
        for(int i = 0 ; i < n ; i++){
            string temp = s.substr(i,1);
           a.push_back(temp);
            left = i-1;
            right = i+1;
            
            while(right < n && s[i] == s[right]){
                right++;
                string temp = s.substr(left+1,right-i);
                    a.push_back(temp);
            }
            while(left >= 0 && right < n && s[left] == s[right]){
                left --;
                right++;
                string temp = s.substr(left+1,right-left-1);
                    a.push_back(temp);
            }
        }
        return a.size();
        
    }
};
