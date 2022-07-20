class Solution {
public:
    int calculate(string s) {
        int curr = 0;
        char operation = '+';
        stack<int> st;
        
        for(int i = 0 ; i < s.length() ; i++){
            if(isdigit(s[i])){
                curr = curr*10 + (s[i] - '0');
            }
            if(!isdigit(s[i]) && !isspace(s[i]) || i == s.length()-1){
                if(operation == '-'){
                    st.push(-curr);
                }
                else if(operation == '+'){
                    st.push(curr);
                }
                else if(operation == '*'){
                    int a = st.top();
                    st.pop();
                    st.push(a*curr);
                }
                else if(operation == '/'){
                    int a = st.top();
                    st.pop();
                    st.push(a/curr);
                }
                curr = 0;
                operation = s[i];
            }
            
        }
        int result = 0;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};
