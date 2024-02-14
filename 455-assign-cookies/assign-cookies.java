class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int ptr1 = 0, ptr2 = 0, ans = 0;
        while (ptr1 < g.length && ptr2 < s.length) {
            if (g[ptr1] <= s[ptr2]) {
                ++ans;
                ++ptr1;
                ++ptr2;
            } else
                ++ptr2;
        }
        return ans;
    }
}