class Solution {
public:
    ListNode *removeZeroSumSublists(ListNode *head) {
        vector<int> v;
        ListNode *node = head;
        unordered_map<int, bool> freq;
        freq[0] = true;
        int currSum = 0;
        while (node) {
            currSum += node->val;
            if (freq[currSum]) {
                int target = currSum;
                currSum -= node->val;
                while (!v.empty() && currSum != target)
                    freq[currSum] = false, currSum -= v.back(), v.pop_back();
            } else
                v.push_back(node->val), freq[currSum] = true;
            node = node->next;
        }
        if (v.empty())
            return NULL;
        node = head;
        for (int i = 0; i < v.size() - 1; ++i)
            node->val = v[i], node = node->next;
        node->val = v.back(), node->next = NULL;
        return head;
    }
};