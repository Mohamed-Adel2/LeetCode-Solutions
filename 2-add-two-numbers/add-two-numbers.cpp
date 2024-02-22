class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        string num1;
        while (l1 != nullptr) {
            num1.push_back(l1->val+'0');
            l1 = l1->next;
        }
        string num2;
        while (l2 != nullptr) {
            num2.push_back(l2->val+'0');
            l2 = l2->next;
        }
        if (num1.size() < num2.size())
            swap(num1, num2);
        while (num2.size() < num1.size())
            num2 += '0';
        string num3;
        int mnSz = min(num1.size(), num2.size());
        int reminder = 0;
        for (int i = 0; i < mnSz; i++) {
            int sum = num1[i] - '0' + num2[i] - '0' + reminder;
            num3 += to_string(sum % 10);
            reminder = (sum > 9);
        }
        if (reminder)
            num3 += '1';
        reverse(num3.begin(), num3.end());
        ListNode *ptr;
        ptr = new ListNode(num3[0] - '0');
        for (int i = 1; i < num3.size(); i++) {
            ListNode *tmp = new ListNode(num3[i] - '0', ptr);
            ptr = tmp;
        }
        return ptr;
    }
};