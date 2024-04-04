class Solution {
public:
    int maxDepth(string s) {
        int currDepth = 0, mxDepth = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                ++currDepth;
            else if (s[i] == ')')
                mxDepth = max(currDepth--, mxDepth);
        }
        return mxDepth;
    }
};