class TrieNode {
public:
    TrieNode *child[26];
    int endsHere = 0;
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    TrieNode *insert(string word) {
        TrieNode *node = root;
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        ++node->endsHere;
        return node;
    }

    bool search(string word) {
        TrieNode *node = root;
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                return false;
            node = node->child[c - 'a'];
        }
        if (node->endsHere > 0) {
            --node->endsHere;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> ans;
        if (words.size() * words[0].size() > s.size())
            return ans;
        Trie trie;
        unordered_map<TrieNode *, int> freq;
        vector<TrieNode *> endpoints(words.size());
        for (int i = 0; i < words.size(); ++i) {
            TrieNode *node = trie.insert(words[i]);
            ++freq[node];
            endpoints[i] = node;
        }
        int windowLen = words.size() * words[0].size(), wordLen = words[0].size();
        for (int i = 0; i + windowLen - 1 < s.size(); ++i) {
            string window = s.substr(i, windowLen);
            int found = 0;
            for (int j = 0; j < window.size(); j += wordLen) {
                bool ok = trie.search(window.substr(j, wordLen));
                if (!ok)
                    break;
                ++found;
            }
            if (found == words.size())
                ans.push_back(i);
            for (auto &node: endpoints)
                node->endsHere = freq[node];
        }
        return ans;
    }
};
