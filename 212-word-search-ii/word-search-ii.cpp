class TrieNode {
public:
    TrieNode *child[26];
    int endsHere = -1;
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
        node->endsHere = idx;
    }
};

class Solution {
public:
    vector<bool> exists;
    vector<string> ans;
    int n, m;
    vector<vector<bool>> visited;
    vector<int> dx, dy;

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        exists.resize(words.size()), n = board.size(), m = board[0].size();
        visited.resize(n, vector<bool>(m));
        dx = {0, 0, 1, -1};
        dy = {1, -1, 0, 0};
        Trie trie;
        for (int i = 0; i < words.size(); i++)
            trie.insert(words[i], i);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (trie.root->child[board[i][j] - 'a'] != NULL)
                    dfs(board, trie.root->child[board[i][j] - 'a'], i, j);
        for (int i = 0; i < words.size(); i++)
            if (exists[i])
                ans.push_back(words[i]);
        return ans;
    }

    void dfs(vector<vector<char>> &board, TrieNode *node, int row, int col) {
        visited[row][col] = true;
        if (~node->endsHere)
            exists[node->endsHere] = true;
        for (int i = 0; i < 4; i++)
            if (valid(row + dx[i], col + dy[i]) && node->child[board[row + dx[i]][col + dy[i]] - 'a'] != NULL)
                dfs(board, node->child[board[row + dx[i]][col + dy[i]] - 'a'], row + dx[i], col + dy[i]);
        visited[row][col] = false;
    }

    bool valid(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]);
    }
};