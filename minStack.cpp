/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
    stack<int> s;
    stack<int> mins;
public:
    void push(int x) {
      
       if(s.empty())
       {
           mins.push(x);
       }
       else
       {
            if(x <= mins.top())
                mins.push(x);
       }
       s.push(x);
    }

    void pop() {
        if(s.empty())
            return;
        int x = s.top();
        s.pop();
        if(x == mins.top())
            mins.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return mins.top();
    }
};
