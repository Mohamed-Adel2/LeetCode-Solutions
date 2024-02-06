class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto str: strs) {
            string tmp = str;
            sort(str.begin(), str.end());
            mp[str].push_back(tmp);
        }
        for (auto i: mp)
            ans.push_back(i.second);
        return ans;
    }
};