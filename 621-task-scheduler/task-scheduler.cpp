class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> freq(26);
        int mxFreq = 0, cnt = 0;
        for (auto &el: tasks) {
            ++freq[el - 'A'];
            if (freq[el - 'A'] == mxFreq)
                ++cnt;
            else if (freq[el - 'A'] > mxFreq)
                mxFreq = freq[el - 'A'], cnt = 1;
        }
        return max((int)tasks.size(), (mxFreq - 1) * (n + 1) + cnt);
    }
};