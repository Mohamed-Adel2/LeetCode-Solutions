class Solution {
    public int maxLength(List<String> arr) {
        int ans = 0;
        int n = arr.size();
        for (int mask = 1; mask < (1 << n); mask++) {
            int freq[] = new int[26];
            boolean valid = true;
            int cnt = 0;
            for (int el = 0; el < n; el++) {
                int bit = (1 << el);
                if ((bit & mask) == bit) {
                    for (int c = 0; c < arr.get(el).length(); c++) {
                        if (freq[arr.get(el).charAt(c) - 'a'] == 1) {
                            valid = false;
                            break;
                        }
                        ++cnt;
                        ++freq[arr.get(el).charAt(c) - 'a'];
                    }
                }
                if (valid)
                    ans = Math.max(ans, cnt);
            }
        }
        return ans;
    }
}