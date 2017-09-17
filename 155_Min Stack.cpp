#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if (x <= min) {
            mystack.push(min);
            min = x;
        }
        mystack.push(x);
    }
    
    void pop() {
        if (mystack.top() == min)  {
            mystack.pop();
            min = mystack.top();
        }
        mystack.pop();
    }
    
    int top() {
        return mystack.top();
    }
    
    int getMin() {
        return min;
    }

private:
    int min = INT_MAX;
    stack<int> mystack;
};


int main() {
	MinStack minStack = new MinStack();
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << " ";
	minStack.pop();
	cout << minStack.top() << " ";
	cout << minStack.getMin() << "\n";

	return 0;
}