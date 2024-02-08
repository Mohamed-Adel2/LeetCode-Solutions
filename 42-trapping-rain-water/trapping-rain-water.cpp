class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] + height[i - 1];
        stack<int> st;
        int left[n], right[n];
        // get first maximum from right
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && height[st.top()] <= height[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            right[st.top()] = -1;
            st.pop();
        }
        // get first maximum from left
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && height[st.top()] < height[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            left[st.top()] = -1;
            st.pop();
        }
        int l = 0, r = n - 1, ans = 0;
        while (l < r) {
            if (right[l] != -1) {
                ans += (right[l] - l - 1) * height[l] - (pre[right[l]] - pre[l + 1]);
                l = right[l];
            }
            if (left[r] != -1) {
                ans += (r - left[r] - 1) * height[r] - (pre[r] - pre[left[r] + 1]);
                r = left[r];
            }
        }
        return ans;
    }
};