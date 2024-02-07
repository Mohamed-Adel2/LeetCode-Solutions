class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int totalSum = 0, currSum = 0, start = 0, sz = gas.size();
        for (int i = 0; i < sz; i++) {
            totalSum += (gas[i] - cost[i]);
            currSum += (gas[i] - cost[i]);
            if (currSum < 0) {
                currSum = 0;
                start  = i + 1;
            }
        }
        if (totalSum < 0)
            return -1;
        return start;
    }
};
