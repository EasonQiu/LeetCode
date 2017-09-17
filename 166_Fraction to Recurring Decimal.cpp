// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// For example,

// Given numerator = 1, denominator = 2, return "0.5".
// Given numerator = 2, denominator = 1, return "2".
// Given numerator = 2, denominator = 3, return "0.(6)".


// 乘除法的时候注意负数，0，无限大
// c++的%是有负数的
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0)  return "NaN";
        // calculate integral
        string integral = "";
        long numer = numerator, denom = denominator;
        if (numer * denom < 0)  integral = "-";
        numer = abs(numer);  denom = abs(denom);
        integral += to_string(numer / denom);
        // calculate decimals
        unordered_map<long, long> pos; // <remainder, postion>
        string decimal = "";
        long remainder = numer % denom, i = 0;
        while (remainder > 0) {
            if (pos.find(remainder) != pos.end()) {
                decimal.insert(pos[remainder], "(");
                decimal += ")";
                break;
            }
            pos[remainder] = i++;
            remainder *= 10;
            decimal += to_string(remainder / denom);
            remainder %= denom;
        }
        return decimal == "" ? integral : integral + "." + decimal;
    }
};