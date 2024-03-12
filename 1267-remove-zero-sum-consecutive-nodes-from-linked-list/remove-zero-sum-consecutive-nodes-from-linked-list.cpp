class Solution {
public:
    ListNode *removeZeroSumSublists(ListNode *head) {
        vector<int> v;
        ListNode *node = head;
        unordered_map<int, bool> freq;
        freq[0] = true;
        int currSum = 0;
        while (node) {
            if (node->val == 0) {
                node = node->next;
                continue;
            }
            currSum += node->val;
            if (freq[currSum]) {
                int target = currSum;
                currSum -= node->val;
                while (!v.empty() && currSum != target)
                    freq[currSum] = false, currSum -= v.back(), v.pop_back();
            } else {
                v.push_back(node->val);
                freq[currSum] = true;
            }
            node = node->next;
        }
        if (v.empty())
            return NULL;
        node = head;
        for (int i = 0; i < v.size(); ++i) {
            node->val = v[i];
            if (i == v.size() - 1)
                node->next = NULL;
            else
                node = node->next;
        }
        return head;
    }
};