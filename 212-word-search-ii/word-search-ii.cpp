class TrieNode {
public:
    TrieNode *child[26];
    string word;
    bool endsHere = false;
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string &word, int idx) {
        TrieNode *node = root;
        for (char c: word) {
            if (node->child[c - 'a'] == NULL)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->endsHere = true;
        node->word = word;
    }
};

class Solution {
public:
    vector<string> ans;
    int n, m;

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        n = board.size(), m = board[0].size();
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        Trie trie;
        for (int i = 0; i < words.size(); i++)
            trie.insert(words[i], i);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (trie.root->child[board[i][j] - 'a'] != NULL)
                    dfs(board, trie.root->child[board[i][j] - 'a'], i, j, dx, dy);
        return ans;
    }

    void dfs(vector<vector<char>> &board, TrieNode *&node, int row, int col, vector<int> &dx, vector<int> &dy) {
        char c = board[row][col];
        board[row][col] = '#';
        if (node->endsHere) {
            ans.push_back(node->word);
            node->endsHere = false;
        }
        for (int i = 0; i < 4; i++)
            if (valid(row + dx[i], col + dy[i]) && board[row + dx[i]][col + dy[i]] != '#' &&
                node->child[board[row + dx[i]][col + dy[i]] - 'a'] != NULL)
                dfs(board, node->child[board[row + dx[i]][col + dy[i]] - 'a'], row + dx[i], col + dy[i], dx, dy);
        board[row][col] = c;
    }

    bool valid(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
};