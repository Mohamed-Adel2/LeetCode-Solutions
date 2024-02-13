class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> sFreq(26), tFreq(26);
        for (int i = 0; i < s.size(); i++) {
            ++sFreq[s[i] - 'a'];
            ++tFreq[t[i] - 'a'];
        }
        for (int i = 0; i < 26; i++)
            if (sFreq[i] != tFreq[i])
                return false;
        return true;
    }
};