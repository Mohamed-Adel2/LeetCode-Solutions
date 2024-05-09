class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        multiset<pair<int, pair<int, int>>> ms;
        for(int i = 0; i < nums1.size(); ++i){
            for(int j = 0; j < nums2.size(); ++j){
                if(ms.size() < k)
                    ms.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                else{
                    if((*ms.rbegin()).first > nums1[i] + nums2[j]){
                        ms.erase(--ms.end());
                        ms.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                    }
                    else
                        break;
                }
            }
        }
        vector<vector<int>> ans(k, vector<int>(2));
        int cnt = 0;
        for(auto &i : ms)
            ans[cnt][0] = i.second.first,  ans[cnt++][1] = i.second.second;
        return ans;
    }
};