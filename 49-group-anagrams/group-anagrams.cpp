class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mp;
        for (auto str: strs) {
            string tmp = str;
            sort(str.begin(), str.end());
            mp[str].push_back(tmp);
        }
        vector<vector<string>> ans;
        for (auto i: mp)
            ans.push_back(i.second);
        return ans;
    }
};