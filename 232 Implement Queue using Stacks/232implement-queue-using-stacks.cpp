class MyQueue {
    private:
    stack<int> stack1; // Stack used for pushing new elements
    stack<int> stack2; // Stack used for popping or peeking

public:
    MyQueue() {
        // Constructor does nothing, stacks are initialized empty by default
       
    }
    
    void push(int x) {
         stack1.push(x);
    }
    
    int pop() {
         if (stack2.empty()) {
            // Transfer elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
             }
        int topElement = stack2.top();
        stack2.pop();
        return topElement;
    }
    
    int peek() {
         if (stack2.empty()) {
            // Transfer elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top(); 
    }
    
    bool empty() {
       return stack1.empty() && stack2.empty();  
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */