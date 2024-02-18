class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> freq(n);
        vector<long long> availableAt(n);
        for (int i = 0; i < meetings.size(); ++i) {
            bool done = false;
            for (int j = 0; j < n; ++j) {
                if (availableAt[j] <= meetings[i][0]) {
                    done = true;
                    availableAt[j] = meetings[i][1], ++freq[j];
                    break;
                }
            }
            if (!done) {
                int room = 0;
                for (int j = 1; j < n; ++j) {
                    if (availableAt[room] > availableAt[j])
                        room = j;
                }
                ++freq[room];
                availableAt[room] = availableAt[room] + meetings[i][1] - meetings[i][0];
            }
        }
        int mxEl = 0;
        for (int i = 1; i < n; ++i)
            if (freq[mxEl] < freq[i]) 
                mxEl = i;
        return mxEl;
    }
};