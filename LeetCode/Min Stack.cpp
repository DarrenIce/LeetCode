class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    int min_;
    MinStack() {
        min_=INT_MAX;
    }
    
    void push(int x) {
        if (x<=min_) {
            s.push(min_);
            min_=x;
        }
        s.push(x);
    }
    
    void pop() {
        int y=s.top();
        s.pop();
        if (y==min_) {
            min_=s.top();
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */