class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
        if (a.size() < b.size())
            swap(a, b);
        while (b.size() < a.size())
            b.push_back('0');
        string ans;
        int carry = 0;
        for (int i = 0; i < a.size(); ++i) {
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