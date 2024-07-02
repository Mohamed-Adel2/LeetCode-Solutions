class DSU {
public:
    vector<int> par;
    vector<int> sz;
    int comp = 0;

    void init(int n) {
        par.resize(n + 1), sz.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
        comp = n;
    }

    int find(int a) {
        if (par[a] == a)
            return a;
        return find(par[a]);
    }

    bool unity(int a, int b, int &ans) {
        a = find(a), b = find(b);
        if (a == b)
            return false;
        comp--;
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a, sz[a] += sz[b];
        ++ans;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        DSU aliceDsu, bobDsu;
        aliceDsu.init(n), bobDsu.init(n);
        int ans = 0;
        for (auto &edge: edges)
            if (edge[0] == 3 && aliceDsu.find(edge[1]) != aliceDsu.find(edge[2]))
                aliceDsu.unity(edge[1], edge[2], ans), bobDsu.unity(edge[1], edge[2], --ans);
        for (auto &edge: edges) {
            if (edge[0] == 1)
                aliceDsu.unity(edge[1], edge[2], ans);
            else if (edge[0] == 2)
                bobDsu.unity(edge[1], edge[2], ans);
        }
        if (aliceDsu.comp == 1 && bobDsu.comp == 1)
            return edges.size() - ans;
        return -1;
    }
};