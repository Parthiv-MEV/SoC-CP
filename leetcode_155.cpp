class MinStack {
    vector<int> stak;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stak.push_back(val);
    }
    
    void pop() {
        stak.pop_back()
    }
    
    int top() {
        return stak[-1];
    }
    
    int getMin() {
        return *min_element(vec.begin(), vec.end())
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */