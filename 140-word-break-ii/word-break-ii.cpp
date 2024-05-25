class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> freq;
        for(auto & word : wordDict)
            freq[word] = true;
        vector<string> ans;
        string curr, sentence;
        solve(0, s, freq, sentence, curr, ans);
        return ans;
    }

    void solve(int idx, string& s, unordered_map<string, bool>& freq, string& sentence, string& curr, vector<string>& ans){
        if(idx >= s.size()){
            if(sentence.back() == ' '){
                sentence.pop_back();
                ans.push_back(sentence);
                sentence.push_back(' ');
            }
            return;
        }

        curr.push_back(s[idx]);
        sentence.push_back(s[idx]);

        if(freq.count(curr)){
            string tmp;
            sentence.push_back(' ');
            solve(idx + 1, s, freq, sentence, tmp, ans);
            sentence.pop_back();
        }

        solve(idx + 1, s, freq, sentence, curr, ans);

        curr.pop_back();
        sentence.pop_back();
    }
};