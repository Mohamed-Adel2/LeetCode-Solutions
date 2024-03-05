class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                char ch = s[left];
                while (left <= right && s[left] == ch)
                    ++left;
                while (right >= left && s[right] == ch)
                    --right;
            } else
                break;
        }
        return right - left + 1;
    }
};