class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int, int>> mns, mxs;
        for(int i = 0; i < arrays.size(); ++i){
            mns.push_back({arrays[i].front(), i});
            mxs.push_back({arrays[i].back(), i});
        }
        sort(mns.begin(), mns.end());
        sort(mxs.begin(), mxs.end());
        if(mns[0].second != mxs.back().second)
            return mxs.back().first - mns[0].first;
        else
            return max(mxs[mxs.size() - 2].first - mns[0].first, mxs.back().first - mns[1].first);
    }
};