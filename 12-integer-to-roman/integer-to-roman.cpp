class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> base, unit;
        base[3] = 'D', base[2] = 'L', base[1] = 'V';
        unit[4] = 'M', unit[3] = 'C', unit[2] = 'X', unit[1] = 'I';
        int curr = 1;
        string ans;
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            if (digit == 0){
                ++curr;
                continue;
            }
            if (digit < 4)
                ans = oneToThree(digit, unit[curr]) + ans;
            else if (digit > 4 && digit < 9)
                ans = fiveToEight(digit - 5, unit[curr], base[curr]) + ans;
            else if (digit == 4) {
                ans = base[curr] + ans;
                ans = unit[curr] + ans;
            } else {
                ans = unit[curr + 1] + ans;
                ans = unit[curr] + ans;
            }
            ++curr;
        }
        return ans;
    }

    string oneToThree(int cnt, char unit) {
        string ret;
        for (int i = 0; i < cnt; i++)
            ret += unit;
        return ret;
    }

    string fiveToEight(int cnt, char unit, char base) {
        string ret;
        ret += base;
        for (int i = 0; i < cnt; i++)
            ret += unit;
        return ret;
    }
};