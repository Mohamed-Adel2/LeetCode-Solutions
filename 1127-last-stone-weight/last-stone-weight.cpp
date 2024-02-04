class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        multiset<int> ms;
        for (auto i: stones)
            ms.insert(i);
        while (ms.size() > 1) {
            int first = *ms.rbegin();
            ms.erase(--ms.end());
            int second = *ms.rbegin();
            ms.erase(--ms.end());
            if (first != second)
                ms.insert(first - second);
        }
        if (ms.size())
            return *ms.begin();
        return 0;
    }
};