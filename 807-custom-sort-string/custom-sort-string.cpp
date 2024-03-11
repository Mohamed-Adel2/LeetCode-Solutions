class Solution {
public:
    string customSortString(string order, string s) {
        int freq[26] = {};
        for (auto &ch: s)
            ++freq[ch - 'a'];
        int idx = 0;
        for (auto &ch: order) {
            for (int i = 0; i < freq[ch - 'a']; ++i)
                s[idx++] = ch;
            freq[ch - 'a'] = 0;
        }
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < freq[i]; ++j)
                s[idx++] = i + 'a';
        return s;
    }
};