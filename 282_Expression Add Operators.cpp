// Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

// Examples: 
// "123", 6 -> ["1+2+3", "1*2*3"] 
// "232", 8 -> ["2*3+2", "2+3*2"]
// "105", 5 -> ["1*0+5","10-5"]
// "00", 0 -> ["0+0", "0-0", "0*0"]
// "3456237490", 9191 -> []


// 解题思路：总共考虑9种情况，number之前之后+-*排列组合。
// 表达式的parse方法一般都是：以+-作为分割标记，当这个number之后碰到紧跟的+-则把当前的值累加到sum中，
// 否则一直计算他的running subsum。
// 通常需要在表达式之前或之后加个+


// corner case: "105",5  "000",0
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        if (num.empty())  return vector<string>();
        ans.clear();
        string express = "";
        dfs(num, target, 0, 0, 0, 1, '+', express);
        return ans;
    }
    
    // 当遇到+-时才把之前的pre_val加到pre_sum中，遇到*继续乘到pre_val中。
    void dfs(const string &num, const int &target, int start, long pre_sum, long pre_val, int sign, char oprt, string &express) {
        if (start == num.size()) {
            if (oprt == '+' && pre_sum == (long)target)  ans.push_back(express.substr(1));
            return;
        }
        string pre_express = express;
        long old_pre_val = pre_val;
        long cur_val = 0;
        for (int i = start; i < num.size(); ++i) {
            if (num[start] == '0' && i > start)  break; // corner cases
            cur_val = cur_val * 10 + num[i] - '0';
            if (oprt == '+' || oprt == '-') {
                pre_val = cur_val;
                sign = (oprt == '+') ? 1 : -1;
            } else {
                pre_val = old_pre_val * cur_val;
            }
            express = pre_express + oprt + num.substr(start, i - start + 1);
            dfs(num, target, i + 1, pre_sum + sign * pre_val, 0, sign, '+', express);
            dfs(num, target, i + 1, pre_sum + sign * pre_val, 0, sign, '-', express);
            dfs(num, target, i + 1, pre_sum, pre_val, sign, '*', express);
        }
        express = pre_express;
    }
        
private:
    vector<string> ans;
};