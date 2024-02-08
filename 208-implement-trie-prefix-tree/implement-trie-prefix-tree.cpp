class TrieNode {
public:
    TrieNode *child[26];
    bool endsHere = false;
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
