class Solution {
public:
    string reverseWords(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ')
                continue;
            string curr;
            while (i < s.size() && s[i] != ' ')
                curr.push_back(s[i++]);
            if(ans.size())
                curr.push_back(' ');
            ans = curr + ans;
        }
        return ans;
    }
};