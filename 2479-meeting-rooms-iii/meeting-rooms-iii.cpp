class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> freq(n);
        set<pair<long long, long long>> availableRooms, unavailableRooms;
        for (int i = 0; i < n; ++i)
            availableRooms.insert({i, 0});
        for (int i = 0; i < meetings.size(); ++i) {
            while (!unavailableRooms.empty() && unavailableRooms.begin()->first < meetings[i][0]) {
                int node = unavailableRooms.begin()->second;
                unavailableRooms.erase(unavailableRooms.begin());
                availableRooms.insert({node, meetings[i][0]});
            }
            if (availableRooms.empty()) {
                long long val = unavailableRooms.begin()->first;
                while (!unavailableRooms.empty() && unavailableRooms.begin()->first == val) {
                    int node = unavailableRooms.begin()->second;
                    long long time = unavailableRooms.begin()->first;
                    availableRooms.insert({node, time + 1});
                    unavailableRooms.erase(unavailableRooms.begin());
                }
            }
            pair<long long, long long> el = *availableRooms.begin();
            availableRooms.erase(availableRooms.begin());
            ++freq[el.first];
            unavailableRooms.insert(
                    {max(el.second + meetings[i][1] - meetings[i][0] - 1, (long long)meetings[i][1] - 1), el.first});

        }
        int mxFreq = 0, mxEl = 101;
        for (int i = 0; i < n; ++i) {
            if (freq[i] > mxFreq) {
                mxEl = i;
                mxFreq = freq[i];
            }
        }
        return mxEl;
    }
};