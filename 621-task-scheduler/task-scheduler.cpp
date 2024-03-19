class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        int sz = tasks.size();
        vector<int> freq(26);
        vector<int> lst(26, -101);
        for (auto &el: tasks)
            ++freq[el - 'A'];
        int ans = 0;
        for (int i = 1; i <= sz; ++i) {
            ++ans;
            int mxAvailable = 0, mxUnavailable = 0;
            char available, unavailable;
            for (int j = 0; j < 26; ++j) {
                if (freq[j] > mxAvailable && ans - lst[j] - 1 >= n) {
                    mxAvailable = freq[j];
                    available = (j + 'A');
                } else if (freq[j] > mxUnavailable && ans - lst[j] - 1 < n) {
                    mxUnavailable = freq[j];
                    unavailable = (j + 'A');
                }
            }
            if (mxAvailable != 0) {
                --freq[available - 'A'];
                lst[available - 'A'] = ans;
            } else {
                --freq[unavailable - 'A'];
                ans += n - (ans - lst[unavailable - 'A'] - 1);
                lst[unavailable - 'A'] = ans;
            }
        }
        return ans;
    }
};