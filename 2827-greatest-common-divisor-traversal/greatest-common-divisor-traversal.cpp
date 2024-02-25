class Solution {
public:
    vector<int> par, sz;

    bool canTraverseAllPairs(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        init(n);
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

    vector<int> factorize(int num) {
        vector<int> ans;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                ans.emplace_back(i);
                while (num % i == 0)
                    num /= i;
            }
        }
        if (num > 1)
            ans.push_back(num);
        return ans;
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