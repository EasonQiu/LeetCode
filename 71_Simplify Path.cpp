#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
    	string answer;
    	stack<string> myStack;
        for (int i = 0; i < path.size(); ++i) {
        	if (path[i] != '/') {
        		myStack.push(path[i]);
        	} else {
        		if (myStack.top() == '/')  continue;
        		
        	}
        }
    }
};

int main() {
	String str = "/a/./b/../../c/";

	Solution s;
	cout << s.simplifyPath(str);
}