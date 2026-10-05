class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token: tokens) {
            if (token.length() > 1 || token[0] >= '0' && token[0] <= '9') {
                int k = 0;
                int p = 1;
                int i = 0;
                if (token[0] == '-') {
                    i = 1;
                    p = -1;
                }
                for (i; i < token.length(); i++) {
                    k = k * 10 + (token[i] - '0');
                }
                st.push(k * p);
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
