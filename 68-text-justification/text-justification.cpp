class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            int j = i;
            int currSz = 0;
            while (j < n && currSz + words[j].size() + (j - i) <= maxWidth) {
                currSz += words[j].size();
                ++j;
            }
            string currLine;
            if (j == n) {
                for (int word = i; word < j - 1; word++) {
                    currLine += words[word];
                    currLine.push_back(' ');
                }
                currLine += words[j - 1];
                while (currLine.size() < maxWidth)
                    currLine.push_back(' ');

            } else {
                int fixedSpaces = (maxWidth - currSz) / max(1, (j - i - 1));
                int extraSpaces = (maxWidth - currSz) % max(1, (j - i - 1));
                for (int word = i; word < j; word++) {
                    currLine += words[word];
                    if (word < j - 1 || j == i + 1)
                        for (int space = 0; space < fixedSpaces + (extraSpaces > 0); space++)
                            currLine.push_back(' ');
                    extraSpaces--;
                }
            }
            i = j - 1;
            ans.push_back(currLine);
        }
        return ans;
    }
};