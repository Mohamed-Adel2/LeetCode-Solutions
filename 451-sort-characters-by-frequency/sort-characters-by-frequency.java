class Solution {
    public String frequencySort(String s) {
        int[] freq = new int[123];
        for (int i = 0; i < s.length(); i++)
            ++freq[s.charAt(i)];
        StringBuilder ans = new StringBuilder();
        while (true) {
            char ch = '-';
            for (int i = '0'; i <= 'z'; i++) {
                if (freq[i] > freq[ch])
                    ch = (char) i;
            }
            if (ch == '-')
                break;
            while (freq[ch] > 0) {
                --freq[ch];
                ans.append(ch);
            }
        }
        return ans.toString();
    }
}