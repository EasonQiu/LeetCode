#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {
        myMin.push(INT_MAX);
    }
    
    void push(int x) {
        myStack.push(x);
        int top = myMin.top();
        if (top <= x)  myMin.push(top);
        else  myMin.push(x);
    }
    
    void pop() {
        myStack.pop();
        myMin.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return myMin.top();
    }

private:
	stack<int> myStack;
	stack<int> myMin;
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