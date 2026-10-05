class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token: tokens) {
            if (token.length() > 1 || token[0] >= '0' && token[0] <= '9') {
                st.push(stoi(token));
                continue;
            }
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            switch (token[0]) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
        return st.top();
    }
};
