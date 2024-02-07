class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n;) {
            int j = i, currSz = 0;
            while (j < n && currSz + words[j].size() + (j - i) <= maxWidth) {
                currSz += words[j].size();
                ++j;
            }
            string currLine;
            if (j == n) {
                for (int word = i; word < j - 1; word++) {
                    currLine += words[word] + ' ';
                }
                currLine += words[j - 1];
                currLine += string(maxWidth - currLine.size(), ' ');
            } else {
                int fixedSpaces = (maxWidth - currSz) / max(1, (j - i - 1));
                int extraSpaces = (maxWidth - currSz) % max(1, (j - i - 1));
                for (int word = i; word < j; word++) {
                    currLine += words[word];
                    if (word < j - 1 || j == i + 1)
                        currLine += string(fixedSpaces + (extraSpaces-- > 0), ' ');
                }
            }
            i = j;
            ans.push_back(currLine);
        }
        return ans;
    }
};