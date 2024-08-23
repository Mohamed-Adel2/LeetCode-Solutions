class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int sz = s.size();
        bool flag = false;
        for (int i = 0; i < sz; ++i) {
            if (s[i] == '(' || s[i] == '+')
                ops.push(s[i]), flag = false;
            else if(s[i] == '-'){
                if(!flag){
                    nums.push(0);
                    flag = true;
                    ops.push(s[i]);
                }
                else
                    ops.push(s[i]), flag = false;
            }
            else if (s[i] == ')') {
                ops.pop();
                apply(nums, ops);
            } else if (s[i] == ' ')
                continue;
            else {
                int num = extractNumber(s, i);
                nums.push(num);
                flag = true;
                apply(nums, ops);
            }
        }
        return nums.top();
    }

    void apply(stack<int> &nums, stack<char> &ops) {
        while (!ops.empty() && ops.top() != '(') {
            char op = ops.top();
            ops.pop();
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            if (op == '-')
                nums.push(num2 - num1);
            else
                nums.push(num2 + num1);
        }
    }

    int extractNumber(string &s, int &idx) {
        string num;
        for (; idx < s.size(); ++idx) {
            if (s[idx] >= '0' && s[idx] <= '9')
                num.push_back(s[idx]);
            else
                break;
        }
        --idx;
        return stoi(num);
    }
};