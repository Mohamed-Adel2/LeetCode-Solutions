class TrieNode {
public:
    TrieNode **child;
    bool endsHere = false;

    TrieNode() {
        child = new TrieNode *[26];
        for (int i = 0; i < 26; ++i)
            child[i] = NULL;
    }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *node = root;
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->endsHere = true;
    }

    bool search(string word) {
        TrieNode *node = root;
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                return false;
            node = node->child[c - 'a'];
        }
        return node->endsHere;
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char c: prefix) {
            if (node->child[c - 'a'] == NULL)
                return false;
            node = node->child[c - 'a'];
        }
        return true;
    }
};