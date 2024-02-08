class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1)
            return s;
        ArrayList<StringBuilder> str = new ArrayList<>();
        for (int i = 0; i < numRows; i++)
            str.add(new StringBuilder());
        int curr = 0, add = 1;
        for (int i = 0; i < s.length(); i++) {
            str.get(curr).append(s.charAt(i));
            curr += add;
            if (curr == numRows) {
                curr = numRows - 2;
                add = -1;
            } else if (curr == -1) {
                curr = 1;
                add = 1;
            }
        }
        StringBuilder ret = new StringBuilder();
        for (int i = 0; i < numRows; i++)
            ret.append(str.get(i));
        return ret.toString();
    }
}