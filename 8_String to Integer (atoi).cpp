// Implement atoi to convert a string to an integer.

// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.


// corner case: leading 0s, sign, overflow, invalid input
class Solution {
public:
    int myAtoi(string str) {
        int i = str.find_first_not_of(' ');
        int sign = 1;
        int num = 0;
        // check sign
        if (str[i] == '-') {
            sign = -1;  ++i;
        } else if (str[i] == '+') {
            ++i;
        }
        while (i < str.size()) {
            if (!isdigit(str[i]))  break;
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] > '7')) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            } else {
                num = num * 10 + str[i++] - '0';
            }
        }
        return sign * num;
    }
};