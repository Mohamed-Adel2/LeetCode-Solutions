class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(auto &c : s)
            ++freq[c];
        int ans = 0, odd = 0;
        for(auto &el : freq){
            ans += el.second - (el.second & 1);
            odd |= (el.second & 1);
        }
        return ans + odd;
    }
};