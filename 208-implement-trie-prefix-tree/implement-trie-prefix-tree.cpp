class TrieNode {
public:
    vector<TrieNode *> v;
    bool endsHere;

    TrieNode() {
        endsHere = false;
        v.resize(26);
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
            if (node->v[c - 'a'] == NULL)
                node->v[c - 'a'] = new TrieNode();
            node = node->v[c - 'a'];
        }
        node->endsHere = true;
    }

    bool search(string word) {
        TrieNode *node = root;
        for (char c: word) {
            if (node->v[c - 'a'] == NULL)
                return false;
            node = node->v[c - 'a'];
        }
        return node->endsHere;
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char c: prefix) {
            if (node->v[c - 'a'] == NULL)
                return false;
            node = node->v[c - 'a'];
        }
        return true;
    }
};