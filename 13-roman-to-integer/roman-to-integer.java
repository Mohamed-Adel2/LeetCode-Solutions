class Solution {
    public int romanToInt(String s) {
        char[] chars = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int[] values = {1, 5, 10, 50, 100, 500, 1000};
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < chars.length; ++i)
            map.put(chars[i], i);
        int mx = 0, ans = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            int tmp = map.get(s.charAt(i));
            if (tmp < mx)
                ans -= values[tmp];
            else {
                ans += values[tmp];
                mx = Math.max(mx, tmp);
            }
        }
        return ans;
    }

}