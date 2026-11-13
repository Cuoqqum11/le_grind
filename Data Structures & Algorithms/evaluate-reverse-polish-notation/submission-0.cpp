class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            string t = tokens[i];
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int right = st.top(); st.pop();
                int left = st.top(); st.pop();
                int result;
                    if      (t == "+") result = left + right;
                    else if (t == "-") result = left - right;
                    else if (t == "*") result = left * right;
                    else               result = left / right;   // only "/" is left
                st.push(result);
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
