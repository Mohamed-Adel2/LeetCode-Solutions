class TrieNode {
public:
    TrieNode *child[26];
    vector<int> wordsInfo;
};

class WordFilter {
public:
    TrieNode *prefix, *suffix;

    WordFilter(vector<string> words) {
        prefix = new TrieNode();
        suffix = new TrieNode();
        for (int i = 0; i < words.size(); ++i)
            addWord(words[i], i);
    }

    void addWord(string &word, int idx) {
        // Add the word in the prefix Trie
        TrieNode *node = prefix;
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
            node->wordsInfo.push_back(idx);

        }

        // Add the word in the suffix Trie
        node = suffix;
        reverse(word.begin(), word.end());
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
            node->wordsInfo.push_back(idx);
        }
    }

    int f(string pre, string suff) {
        reverse(suff.begin(), suff.end());
        // Find strings start with pre
        TrieNode *node1 = prefix;
        for (char c: pre) {
            if (node1->child[c - 'a'] == NULL)
                return -1;
            node1 = node1->child[c - 'a'];
        }

        // Find strings start with suff
        TrieNode* node2 = suffix;
        for (char c: suff) {
            if (node2->child[c - 'a'] == NULL)
                return -1;
            node2 = node2->child[c - 'a'];
        }

        return getMaxIdx(node1->wordsInfo, node2->wordsInfo);
    }

    int getMaxIdx(vector<int>& pre, vector<int> &suff) {
        int p1 = 0, p2 = 0;
        int idx = -1;
        while (p1 < pre.size() && p2 < suff.size()) {
            if (pre[p1] == suff[p2])
                idx = pre[p1], ++p1, ++p2;
            else if (pre[p1] < suff[p2])
                ++p1;
            else
                ++p2;
        }
        return idx;
    }
};