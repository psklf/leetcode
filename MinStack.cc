#include<stack>
#include<iostream>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
    	m_stack.push(x);
		// judge
		if (m_min_stack.empty()) {
            m_min_stack.push(x);
            return;
        }

        if (m_min_stack.top() > x) {
            m_min_stack.push(x);
        } else {
            m_min_stack.push(m_min_stack.top());
        }
    }
    
    void pop() {
        if (m_stack.empty()) {
            return;
        }
        m_stack.pop();
        m_min_stack.pop();
    }
    
    int top() {
        if (m_stack.empty()) {
            return 0;
        }

        return m_stack.top();
    }
    
    int getMin() {
        if (m_min_stack.empty()) {
            return 0;
        }
        return m_min_stack.top();
    }
private:
    std::stack<int> m_stack;
    std::stack<int> m_min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main() {
    MinStack obj = MinStack();
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    std::cout<<"return "<<obj.getMin()<<std::endl;
    obj.pop();
    std::cout<<"return "<<obj.top()<<std::endl;
    std::cout<<"return "<<obj.getMin()<<std::endl;
}
