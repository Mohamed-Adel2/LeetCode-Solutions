class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp, revmp;
        for (int i = 0; i < s.size(); i++) {
            if (mp.count(s[i])) {
                if (mp[s[i]] != t[i])
                    return false;
            } else if (mp.count(revmp[t[i]]))
                return false;
            mp[s[i]] = t[i];
            revmp[t[i]] = s[i];
        }
        return true;
    }
};