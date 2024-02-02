class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int l = 0, r = 1;
        int ans = 0;
        unordered_map<char,int> freq;
        freq[s[0]]++;
        while(r<s.size()){
            if(freq[s[r]]){
                ans = max(ans, r-l);
                --freq[s[l]];
                ++l;
            }
            else{
                ++freq[s[r]];
                ++r;
            }
        }
        ans = max(ans, r-l);
        return ans;
    }
};