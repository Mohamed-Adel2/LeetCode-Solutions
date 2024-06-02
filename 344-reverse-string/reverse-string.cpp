class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz = s.size();
        for(int i = 0; i < sz / 2; ++i)
            swap(s[i], s[sz - i - 1]);
    }
};