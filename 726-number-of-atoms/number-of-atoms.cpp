class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> freq;
        vector<int> count, openIdx;
        vector<long> multiply;
        vector<long> devide;
        vector<string> elements;
        for (int i = 0; i < formula.size(); ++i) {
            pair<string, int> element = getElement(formula, i);
            elements.push_back(element.first);
            count.push_back(element.second);
            multiply.push_back(1);
            devide.push_back(1);
            if (element.first == "(")
                openIdx.push_back(elements.size() - 1);
            else if (element.first == ")") {
                int start = openIdx.back(), end = elements.size() - 1;
                openIdx.pop_back();
                multiply[start] *= element.second;
                devide[end] *= element.second;
            }
        }
        for (int i = 1; i < multiply.size(); ++i){
            multiply[i] = multiply[i] * multiply[i - 1] / devide[i];
        }
        for (int i = 0; i < elements.size(); ++i) {
            if(elements[i] != "(" && elements[i] != ")")
                freq[elements[i]] += count[i] * multiply[i];
        }
        string ans;
        for (auto &i: freq)
            ans = ans + i.first + (i.second > 1 ? to_string(i.second) : "");
        return ans;
    }

    pair<string, int> getElement(string &formula, int &idx) {
        if (formula[idx] == '(')
            return {"(", 1};
        if (formula[idx] == ')') {
            int num = 0;
            ++idx;
            while (idx < formula.size() && formula[idx] >= '0' && formula[idx] <= '9')
                num = num * 10 + (formula[idx++] - '0');
            --idx;
            if (!num)
                num = 1;
            return {")", num};
        }
        string element;
        element += formula[idx++];
        int cnt = 0;
        while (idx < formula.size() && formula[idx] >= 'a' && formula[idx] <= 'z')
            element += formula[idx++];
        while (idx < formula.size() && formula[idx] >= '0' && formula[idx] <= '9')
            cnt = cnt * 10 + (formula[idx++] - '0');
        if (!cnt)
            cnt = 1;
        --idx;
        return {element, cnt};
    }
};