class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            swap(a, b);
        while (b.size() < a.size())
            b = '0' + b;
        string ans;
        int carry = 0;
        for (int i = a.size() - 1; i >= 0 ; --i) {
            int sum = ((a[i] - '0') + (b[i] - '0') + carry);
            ans.push_back((sum % 2) + '0');
            carry = (sum > 1);
        }
        if (carry)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};