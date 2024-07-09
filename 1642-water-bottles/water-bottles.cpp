class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = 0, ans = 0;
        while(numBottles > 0){
            ans += numBottles;
            emptyBottles += numBottles;
            numBottles = emptyBottles / numExchange;
            emptyBottles -= (numBottles * numExchange);
        }
        return ans;
    }
};