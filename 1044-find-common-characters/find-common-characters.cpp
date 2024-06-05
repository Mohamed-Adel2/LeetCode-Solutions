class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        for(char c = 'a'; c <= 'z'; ++c){
            int cnt = 101;
            for(int i = 0; i < words.size(); ++i){
                int wordCnt = 0;
                for(int j = 0; j < words[i].size(); ++j)
                    if(words[i][j] == c)
                        ++wordCnt;
                cnt = min(cnt, wordCnt);
            }
            string tmp;
            tmp +=c;
            for(int i = 0;i < cnt; ++i)
                ans.push_back(tmp);
        }
        return ans;
    }
};