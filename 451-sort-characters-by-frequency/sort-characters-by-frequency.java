class Solution {
    public String frequencySort(String s) {
        HashMap<Character, Integer> freq = new HashMap<>();
        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        StringBuilder ans = new StringBuilder();
        char ch = 'a';
        int cnt;
        int sz = freq.size();
        for (int i = 0; i < sz; i++) {
            cnt = 0;
            for (Map.Entry<Character, Integer> e : freq.entrySet()) {
                if (e.getValue() > cnt) {
                    ch = e.getKey();
                    cnt = e.getValue();
                }
            }
            if (cnt == 0)
                break;
            for (int c = 0; c < cnt; c++)
                ans.append(ch);
            freq.remove(ch);
        }
        return ans.toString();
    }
}