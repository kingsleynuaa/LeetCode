class Queue {
public:
    // Push element x to the back of queue.
    
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(s2.empty())
        {
            if(s1.empty()) return;
            while(!s1.empty())
            {
                cout << s1.top();
                s2.push(s1.top());
                s1.pop();
            }
          
        }
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if(!s2.empty()) return s2.top();
        else if(s2.empty())
        {
            if(s1.empty()) return 0;  //这个地方如果都为空的话，返回什么？能保证不出现这种现象喽？
            else 
            {            
                while(!s1.empty())
                {
                s2.push(s1.top());
                s1.pop();
                }
            }
         }
         return s2.top();
        
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
        
    }
private:
    stack<int> s1;
    stack<int> s2;
};
