class MinStack {
public:
    vector<int> stack, mins;
    MinStack() {
    }
    
    void push(int val) {
        stack.push_back(val);
        if(mins.empty() || val <= mins.back())
            mins.push_back(val);
    }
    
    void pop() {
        int top = stack.back();
        stack.pop_back();
        if(top == mins.back())
            mins.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return mins.back();
    }
};
