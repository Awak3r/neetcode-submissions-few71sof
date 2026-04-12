class Solution {
public:
    bool isValid(string s) {
        stack<char> sss;
        char cur;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
                sss.push(s[i]);
            } else{
                if (sss.empty()) return false;
                if (s[i] == ']'){
                    cur = sss.top();
                    sss.pop();
                    if (cur != '[') {
                        return false;
                    }
                }
                else if (s[i] == ')'){
                    cur = sss.top();
                    sss.pop();
                    if (cur != '(') {
                        return false;
                    }
                }
                else if (s[i] == '}'){
                    cur = sss.top();
                    sss.pop();
                    if (cur != '{') {
                        return false;
                    }
                }
            }
        }
        if (!sss.empty()){
            return false;
        }
        return true;
    }
};
