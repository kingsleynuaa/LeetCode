class Stack {
public:
    queue<int> Q1;   //the size of Q1 may no more than 1, there are at least one queue will play the role of Q1
    queue<int> Q2;
    int q1_size = Q1.size(), q2_size = Q2.size();
    
    // Push element x onto stack.
    void push(int x) {
          Q1.push(x);
        if(Q1.size() > 1)
        {
            Q2.push(Q1.front());
            Q1.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        Q1.pop();
        int temp = Q2.size();
        while(temp-- != 0)
        {
            push(Q2.front());
            Q2.pop();
        }
        
    }

    // Get the top element.
    int top() {
        if(Q1.size() == 1)
            return Q1.front();
        else return 0;
    }

    // Return whether the stack is empty.
    bool empty() {
        return (Q1.size() == 0);
        
    }
};
