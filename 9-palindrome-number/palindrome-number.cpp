class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int sz = num.size();
        for (int i = 0; i < sz / 2; ++i)
            if (num[i] != num[sz - 1 - i])
                return false;
        return true;
    }
};