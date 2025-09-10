#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minstack;

    MinStack() {
        
    }
    
    void push(int val) {
        if(!st.empty())
        {
            st.push(val);
            if(val<minstack.top())
            minstack.push(val);
            else
            minstack.push(minstack.top());
        }
        else
        {
            st.push(val);
            minstack.push(val);
        }
    }
    
    void pop() {
        st.pop();
        minstack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
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