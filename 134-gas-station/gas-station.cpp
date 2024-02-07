class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sz = (int) gas.size();
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] < cost[i])
                continue;
            int currGas = gas[i] - cost[i];
            int currStation = (i + 1) % sz;
            while (currGas + gas[currStation] >= cost[currStation]) {
                currGas = currGas + gas[currStation] - cost[currStation];
                currStation = (currStation + 1) % sz;
                if (currStation == i)
                    break;

            }
            if (currStation == i)
                return i;
            if(currStation < i)
                break;
            i = currStation;
        }
        return -1;
    }
};