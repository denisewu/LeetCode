/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
class MinStack {
    stack<int> s;
    int min;
    public:
    void push(int x) {
        if(s.empty())
        {
            min = x;
            s.push(0);
            
        }
    }

    void pop() {
        if(!s.empty())
        {
            int x = s.top();
            if(x == min)
            {
                s.pop();
                min = s.top();
               
            }
            s.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min;
        
    }
};
