class TrieNode {
public:
    TrieNode *child[26];
    vector<int> words;
};

class Trie {
public:
    TrieNode *root;

    Trie(vector<string>& str) {
        root = new TrieNode();
        int idx = 0;
        for(auto & s : str)
            insert(s, idx++);
    }

    void insert(string word, int idx) {
        TrieNode *node = root;
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
            if(node->words.size() < 3)
                node->words.push_back(idx);
        }
    }

    vector<vector<string>> search(string word, vector<string>& str) {
        TrieNode *node = root;
        vector<vector<string>> v(word.size());
        int cnt = 0;
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                break;
            node = node->child[c - 'a'];
            for(int i = 0; i < node->words.size(); ++i)
                v[cnt].push_back(str[node->words[i]]);
            ++cnt;
        }
        return v;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Trie t(products);
        return t.search(searchWord, products);   
    }
};