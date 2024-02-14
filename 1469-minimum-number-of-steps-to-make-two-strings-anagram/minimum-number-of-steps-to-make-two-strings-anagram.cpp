class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sFreq(26), tFreq(26);
        for (int i = 0; i < s.size(); ++i)
            sFreq[s[i] - 'a']++, tFreq[t[i] - 'a']++;
        int ans = 0;
        for (int i = 0; i < 26; i++)
            if (sFreq[i] > tFreq[i])
                ans += sFreq[i] - tFreq[i];
        return ans;
    }
};