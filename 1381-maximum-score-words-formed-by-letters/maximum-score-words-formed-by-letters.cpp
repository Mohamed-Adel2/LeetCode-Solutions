class Solution {
public:
    int ans = 0;

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        int sz = words.size();
        unordered_map<char, int> charFreq;
        vector<bool> valid(sz, true);
        vector<int> wordScore(sz);
        for (auto &c: letters)
            ++charFreq[c];
        for (int i = 0; i < sz; ++i) {
            unordered_map<char, int> wordFreq;
            for (int j = 0; j < words[i].size(); ++j) {
                if (++wordFreq[words[i][j]] > charFreq[words[i][j]]) {
                    valid[i] = false;
                    break;
                }
            }
            if (valid[i]) {
                for (auto &c: words[i])
                    wordScore[i] += score[c - 'a'];
            }
        }
        solve(0, words, valid, wordScore, charFreq, 0);
        return ans;
    }

    void
    solve(int idx, vector<string> &word, vector<bool> &valid, vector<int> &scores, unordered_map<char, int> &charFreq,
          int sum) {
        if (idx >= word.size())
            return void(ans = max(ans, sum));
        if (valid[idx]) {
            bool ok = true;
            for (auto &c: word[idx]) {
                --charFreq[c];
                if (charFreq[c] < 0)
                    ok = false;
            }
            if (ok)
                solve(idx + 1, word, valid, scores, charFreq, sum + scores[idx]);
            for (auto &c: word[idx])
                ++charFreq[c];
        }
        solve(idx + 1, word, valid, scores, charFreq, sum);
    }
};