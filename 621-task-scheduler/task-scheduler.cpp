class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> freq(26);
        int mxFreq = 0, cnt = 0;
        for (auto &el: tasks) {
            int &fr = freq[el - 'A'];
            ++fr;
            if (fr == mxFreq)
                ++cnt;
            else if (fr > mxFreq)
                mxFreq = fr, cnt = 1;
        }
        return max((int) tasks.size(), (mxFreq - 1) * (n + 1) + cnt);
    }
};