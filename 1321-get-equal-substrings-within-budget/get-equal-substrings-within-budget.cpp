class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int currCost = 0, l = 0, r = 0, ans = 0;
        while(r < s.size()){
            currCost += abs(s[r] - t[r]);
            if(currCost > maxCost){
                ans = max(ans, r - l);
                currCost -= abs(s[l] - t[l++]);
            }
            ++r;
        }
        ans = max(ans, r - l);
        return ans;
    }
};