#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        std::stack<int> tmpStack;
        int size = stack.size();
        for (int i = 0; i < size; ++i) {
            tmpStack.push(stack.top());
            stack.pop();
        }
        stack.push(x);
        for (int i = 0; i < size; ++i) {
            stack.push(tmpStack.top());
            tmpStack.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = stack.top();
        stack.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack.empty();
    }
private:
    std::stack<int> stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main() {
    MyQueue obj = MyQueue();
    obj.push(1);
    obj.push(2);
    obj.push(3);
    cout<<"peek"<<obj.peek()<<"pop "<<obj.pop()<<endl;
    cout<<"another peek"<<obj.peek()<<"pop "<<obj.pop()<<endl;
    cout<<"another peek"<<obj.peek()<<"pop "<<obj.pop()<<endl;
    cout<<"Empty? "<<obj.empty()<<endl;
    return 0;
}
