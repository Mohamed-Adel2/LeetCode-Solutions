class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        if (tokens.empty())
            return 0;
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1, totalScore = 0;
        while (left < right) {
            if (power >= tokens[left])
                ++totalScore, power -= tokens[left++];
            else if (totalScore > 0)
                --totalScore, power += tokens[right--];
            else
                break;
        }
        return totalScore + (power >= tokens[left]);
    }
};