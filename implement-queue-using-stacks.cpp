class MyQueue {
    // FRONT ====|s1    s2|==== BACK
    stack<int> s1, s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s2.push(x);
    }
    
    int front(bool remove){
        if(s1.empty()){
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        
        auto result = s1.top();
        if(remove){
            s1.pop();
        }
        return result;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        return front(true);
    }
    
    /** Get the front element. */
    int peek() {
        return front(false);
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
