class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        vector<int> v;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ')') {
                while (st.top() != '(')
                    v.push_back(st.top()), st.pop();
                st.pop();
                for (int j = 0; j < v.size(); ++j)
                    st.push(v[j]);
                v.clear();
            } else
                st.push(s[i]);
        }
        string ans;
        while (!st.empty())
            ans.push_back(st.top()), st.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};