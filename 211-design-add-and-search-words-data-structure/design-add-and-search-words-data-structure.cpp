class TrieNode {
public:
    TrieNode *child[26];
    bool endsHere = false;
};

class WordDictionary {
public:
    TrieNode *root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode *node = root;
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->endsHere = true;
    }

    bool search(string word) {
        return startFromHere(root, word, 0);
    }

    bool startFromHere(TrieNode *curr, string &s, int idx) {
        TrieNode *node = curr;
        for (int i = idx; i < s.size(); i++) {
            if (s[i] == '.') {
                bool canComplete = false;
                for (int child = 0; child < 26; child++) {
                    if (node->child[child] != NULL)
                        canComplete |= startFromHere(node->child[child], s, i + 1);
                    if(canComplete)
                        return canComplete;
                }
                return canComplete;
            } else {
                if (node->child[s[i] - 'a'] == NULL)
                    return false;
                node = node->child[s[i] - 'a'];
            }
        }
        return node->endsHere;
    }
};