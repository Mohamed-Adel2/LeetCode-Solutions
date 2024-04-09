class Solution {
public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        int ans = 0, val = tickets[k];
        for (int i = 0; i < tickets.size(); ++i)
            ans += min(tickets[i], val - (i > k));
        return ans;
    }
};
