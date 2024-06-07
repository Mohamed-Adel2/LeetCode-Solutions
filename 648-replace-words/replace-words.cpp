class TrieNode {
public:
    TrieNode *child[26];
    int minEndsHere = -1;
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string& word, vector<string>& words, int idx) {
        TrieNode *node = root;
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        if(node -> minEndsHere == -1)
            node->minEndsHere = idx;
        else if(words[node -> minEndsHere].size() > word.size())
            node -> minEndsHere = idx;
    }

    int search(string word) {
        TrieNode *node = root;
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                return -1;
            node = node->child[c - 'a'];
            if(node -> minEndsHere != -1)
                return node -> minEndsHere;
        }
        return node->minEndsHere;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();
        for(int i = 0; i < dictionary.size(); ++i)
            trie->insert(dictionary[i], dictionary, i);
        string ans;
        for(int i = 0; i < sentence.size(); ++i){
            string tmp;
            while(i < sentence.size() && sentence[i] != ' ')
                tmp += sentence[i++];
            int idx = trie->search(tmp);
            if(idx == -1)
                ans += tmp + " ";
            else
                ans += dictionary[idx] + " ";
        }
        ans.pop_back();
        return ans;
    }
};