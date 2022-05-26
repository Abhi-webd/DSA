class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        char temp;
        for(int i = 0 ; i <s.length() ; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                p.push(s[i]);
                continue;
            }
            if(p.empty()){
                return false;
            }
            if(s[i] == ']'){
                temp = p.top();
                p.pop();
                if(temp != '['){
                    return false;
                }
            }
            else if(s[i] == '}'){
                temp = p.top();
                p.pop();
                if(temp != '{'){
                    return false;
                }
            }
            else{
                temp = p.top();
                p.pop();
                if(temp != '('){
                    return false;
                }
            }
        }
        if(p.empty()){
            return true;
        }
        return false;
    }
};
