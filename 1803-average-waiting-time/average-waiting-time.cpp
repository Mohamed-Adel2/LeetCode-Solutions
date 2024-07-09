class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long ans = 0, currTime = 0;
        for(int i = 0; i < customers.size(); ++i){
            if(currTime > customers[i][0])
                ans += currTime - customers[i][0];
            else
                currTime = customers[i][0];
            ans += customers[i][1];
            currTime += customers[i][1];
        }
        return (double)ans / customers.size();
    }
};