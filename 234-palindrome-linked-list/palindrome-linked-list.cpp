class Solution {
public:
    bool isPalindrome(ListNode *head) {
        string s;
        while (head) {
            s.push_back(head->val), head = head->next;
        }
        int sz = s.size();
        for (int i = 0; i < sz / 2; ++i)
            if (s[i] != s[sz - i - 1])
                return false;
        return true;
    }
};