class MinStack {
public:
    //using 2 stack approach for this
    stack<int> curr_stack;
    stack<int> min_stack;
    MinStack() {
    }
    
    void push(int val) {
        curr_stack.push(val);
        if(min_stack.size()==0){
            min_stack.push(val);
        }
        else{
            min_stack.push(min(min_stack.top(),val));
        }
    }
    
    void pop() {
        min_stack.pop();
        curr_stack.pop();
    }
    
    int top() {
        return curr_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
