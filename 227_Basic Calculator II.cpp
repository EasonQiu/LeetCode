// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

// You may assume that the given expression is always valid.

// Some examples:
// "3+2*2" = 7
// " 3/2 " = 1
// " 3+5 / 2 " = 5
// Note: Do not use the eval built-in library function.


// 最终计算的时候以加减符号位一个计算单位，最外层以运算符号为分割，读取数字是在每次读取运算符号之后
// stream读取int的时候碰到-号也会读取
class Solution {
 public:
  int calculate(string s) {
  	stringstream stream("+" + s + "+0");
  	int sum = 0, pre_val = 0, cur_val;
  	char op;
  	while (stream >> op) {
  		if (op == '+' || op == '-') {
  			sum += pre_val;
  			stream >> pre_val;
  			pre_val *= 44 - op; // (op == '+') ? 1 : -1;
  		} else {
  			stream >> cur_val;
  			if (op == '*') {
  				pre_val *= cur_val;
  			} else {
  				pre_val /= cur_val;
  			}
  		}
  	}
  	return sum;
  }
};