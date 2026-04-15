class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sss;
        int v1, v2;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                v1 = sss.top();
                sss.pop();
                v2 = sss.top();
                sss.pop();

                if (tokens[i] == "+") {
                    sss.push(v2 + v1);
                } else if (tokens[i] == "-") {
                    sss.push(v2 - v1);
                } else if (tokens[i] == "*") {
                    sss.push(v2 * v1);
                } else {
                    sss.push(v2 / v1);
                }
            } else {
                sss.push(stoi(tokens[i]));
            }
        }

        return sss.top();
    }
};