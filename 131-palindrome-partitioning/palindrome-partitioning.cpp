class Solution {
public:
    vector<vector<string>> partition(string s) {
        int sz = s.size();
        set<vector<string>> ans;
        for(int msk = 0; msk < (1 << sz); ++msk){
            string sub="";
            vector<string> subAns;
            for(int j = 0; j<s.size(); ++j){
                sub.push_back(s[j]);
                if(msk & (1<<j)){
                    subAns.push_back(sub);
                    sub = "";
                }
            }
            if(!sub.empty()){
                subAns.push_back(sub);
            }
            bool flg=true;
            for(auto s : subAns){
                if(!isPalindrome(s)) flg = false;
            }

            if(flg) ans.insert(subAns);
        }
        vector<vector<string>> ret;
        for(auto v : ans)
            ret.push_back(v);
        return ret;
    }

    bool isPalindrome(string s){
        for(int i = 0; i<s.size()/2; ++i)
            if(s[i] != s[s.size()-i-1])
                return false;
        return true;
    }
};