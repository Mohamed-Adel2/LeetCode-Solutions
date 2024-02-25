#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<int> par, sz, spf;

    bool canTraverseAllPairs(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        sieve(nums.back()), init(n);
        unordered_map<int, int> freq;
        for (int idx = 0; idx < n; ++idx) {
            vector<int> factors = factorize(nums[idx]);
            for (int i = 0; i < factors.size(); ++i) {
                if (freq.count(factors[i]))
                    unity(freq[factors[i]], idx);
                else
                    freq[factors[i]] = idx;
            }
        }
        return sz[find(0)] == n;
    }

    void sieve(int n) {
        spf.resize(n + 2);
        for (int i = 2; i <= n; ++i)
            spf[i] = i;
        spf[0] = spf[1] = -1;
        for (int i = 2; i <= n / i; i++)
            if (spf[i] == i)
                for (int j = i * i; j <= n; j += i)
                    if (spf[j] == j)
                        spf[j] = i;
    }

    vector<int> factorize(int n) {
        vector<int> v;
        while (n > 1) {
            int cur = spf[n];
            while (n % cur == 0)
                n /= cur;
            v.emplace_back(cur);
        }
        return v;
    }

    void init(int n) {
        par.resize(n), sz.resize(n);
        for (int i = 0; i < n; ++i)
            par[i] = i, sz[i] = 1;
    }

    int find(int a) {
        if (par[a] == a)
            return a;
        return find(par[a]);
    }

    bool unity(int a, int b) {
        a = find(a), b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a, sz[a] += sz[b];
        return true;
    }
};