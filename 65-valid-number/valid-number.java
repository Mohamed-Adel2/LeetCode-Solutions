class Solution {
    public boolean isNumber(String s) {
        boolean integer = true;
        boolean result = true;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '.')
                integer = false;
            else if (s.charAt(i) == 'e' || s.charAt(i) == 'E') {
                start = i + 1;
                if (integer)
                    result = isInteger(s.substring(0, i));
                else
                    result = isDecimal(s.substring(0, i));
                integer = true;
                break;
            }
        }
        if (integer)
            result &= isInteger(s.substring(start));
        else
            result &= isDecimal(s.substring(start));
        return result;
    }

    public boolean isInteger(String s) {
        if (s.isEmpty())
            return false;
        int i = 0;
        if (s.charAt(i) == '+' || s.charAt(i) == '-')
            ++i;
        if (i == s.length())
            return false;
        for (; i < s.length(); i++) {
            if (s.charAt(i) < '0' || s.charAt(i) > '9')
                return false;
        }
        return true;
    }

    public boolean isDecimal(String s) {
        int i = 0, cnt = 0;
        if (s.charAt(i) == '+' || s.charAt(i) == '-')
            ++i;
        while (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
            cnt |= 1;
            ++i;
        }
        if (s.charAt(i++) != '.')
            return false;
        while (i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
            cnt |= 2;
            ++i;
        }
        return (i == s.length() && cnt >= 1);
    }
}