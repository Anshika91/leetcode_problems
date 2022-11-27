class MyQueue {
public:
    stack<int> stk;
    
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while(!stk.empty()){
            tmp.push(stk.top());
            stk.pop();
        }
        stk.push(x);
        while(!tmp.empty()){
            stk.push(tmp.top());
            tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = stk.top();
        stk.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        return stk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
};
