class MinStack {
private:
    struct Data {
        int value;
        int currMin;
    };
    stack<Data> stk;
public:
    MinStack() = default;
    
    void push(int value) {
        if (stk.empty()) {
            stk.push({ value, value });
        }
        else {
            stk.push({ value, min(value, stk.top().currMin ) });
        }
    }
    
    void pop() {
        if (!stk.empty()) {
            stk.pop();
        }
    }
    
    int top() {
        if (!stk.empty()) {
            return stk.top().value;
        }
        return -1;
    }
    
    int getMin() {
        if (!stk.empty()) {
            return stk.top().currMin;
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */