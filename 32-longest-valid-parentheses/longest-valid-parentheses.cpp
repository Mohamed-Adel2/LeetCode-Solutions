class Solution {
public:
int longestValidParentheses(string& s) {
    int n = s.size();
    vector<int> v(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            st.push(i);
         else {
            if (!st.empty()) {
                v[i] = 1;
                v[st.top()] = 1;
                st.pop();
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int locAns = 0;
        while (i < n && v[i] == 1) {
            i++;
            locAns++;
        }
        ans = max(ans, locAns);
    }
    return ans;
}

};