class Solution {
public:
int dp[105][105];
int n;

bool compare(int i, int j, vector<vector<int>> &cuboids) {
    return (cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]);
}

int solve(int prv, int curr, vector<vector<int>> &cuboids) {
    if (curr == n)
        return 0;
    int &ret = dp[prv][curr];
    if (~ret)
        return ret;
    ret = solve(prv, curr + 1, cuboids);
    if (compare(prv, curr, cuboids))
        ret = max(cuboids[curr][0] + solve(curr, curr + 1, cuboids), ret);
    return ret;
}

int maxHeight(vector<vector<int>> &cuboids) {
    cuboids.push_back({150, 150, 150});
    for (auto &i: cuboids)
        sort(i.rbegin(), i.rend());
    sort(cuboids.rbegin(), cuboids.rend());
    memset(dp, -1, sizeof(dp));
    n = cuboids.size();
    return solve(0, 1, cuboids);
}
};