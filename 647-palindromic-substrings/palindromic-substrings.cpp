class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i)
            ans += countPalindrome(s, i, false) + countPalindrome(s, i, true);
        return ans;
    }

    int countPalindrome(string &s, int idx, bool even) {
        int l = idx - even, r = idx;
        while (l >= 0 && r < s.size()) {
            if (s[l] != s[r])
                break;
            --l, ++r;
        }
        return (r - l - 1 + !even) / 2;
    }
};