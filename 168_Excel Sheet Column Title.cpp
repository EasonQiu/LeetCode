#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        return (n == 0) ? "" : convertToTitle((n - 1) / 26) + (char)((n - 1) % 26 + 65);
    }
};

int main() {
	Solution s;
	cout << s.convertToTitle(26) << endl;
	return 0;
}