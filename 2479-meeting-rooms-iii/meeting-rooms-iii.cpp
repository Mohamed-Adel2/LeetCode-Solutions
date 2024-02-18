class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> freq(n);
        vector<long long> availableAt(n);
        int mxEl = 0;
        for (int i = 0; i < meetings.size(); ++i) {
            bool done = false;
            for (int j = 0; j < n; ++j) {
                if (availableAt[j] <= meetings[i][0]) {
                    done = true;
                    availableAt[j] = meetings[i][1], ++freq[j];
                    if (freq[j] > freq[mxEl])
                        mxEl = j;
                    else if (freq[j] == freq[mxEl])
                        mxEl = min(j, mxEl);
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
                if (freq[room] > freq[mxEl])
                    mxEl = room;
                else if (freq[room] == freq[mxEl])
                    mxEl = min(room, mxEl);
                availableAt[room] = availableAt[room] + meetings[i][1] - meetings[i][0];
            }
        }
        return mxEl;
    }
};