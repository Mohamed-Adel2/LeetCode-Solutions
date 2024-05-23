class TrieNode {
public:
    vector<TrieNode *> child;
    bool endsHere;

    TrieNode() {
        endsHere = false;
        child = vector<TrieNode *>(26, NULL);
    }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *curr = root;
        int idx = 0;
        while (idx < word.size()) {
            if (curr->child[word[idx] - 'a'] == NULL)
                curr->child[word[idx] - 'a'] = new TrieNode();
            curr = curr->child[word[idx] - 'a'];
            ++idx;
        }
        curr->endsHere = true;
    }

    bool search(string word) {
        TrieNode *curr = root;
        int idx = 0;
        while (idx < word.size()) {
            if (curr->child[word[idx] - 'a'] == NULL)
                return false;
            curr = curr->child[word[idx] - 'a'];
            ++idx;
        }
        return curr->endsHere;
    }

    bool startsWith(string prefix) {
        TrieNode *curr = root;
        int idx = 0;
        while (idx < prefix.size()) {
            if (curr->child[prefix[idx] - 'a'] == NULL)
                return false;
            curr = curr->child[prefix[idx] - 'a'];
            ++idx;
        }
        return true;
    }
};