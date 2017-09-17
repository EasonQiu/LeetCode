// Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

// If there is no solution for the equation, return "No solution".

// If there are infinite solutions for the equation, return "Infinite solutions".

// If there is exactly one solution for the equation, we ensure that the value of x is an integer.

// Example 1:
// Input: "x+5-3+x=6+x-2"
// Output: "x=2"

class Solution {
public:
    string solveEquation(string equation) {
        vector<vector<int> > coef(2, vector<int>(2)); // {x, num}
        int k = 0; // denote on the left or right side of equations
        int i = 0;
        int sign = 1;
        while (i < equation.size()) {
            // split by operators
            int j = i;
            while (j < equation.size() && equation[j] != '+' && equation[j] != '-' && equation[j] != '=')  ++j;
            // parse the number || x between operators
            if (i != j) {
                if (equation[j - 1] == 'x') {
                    coef[k][0] += (i + 1 == j) ? sign : sign * stoi(equation.substr(i, j - i - 1));
                } else {
                    coef[k][1] += sign * stoi(equation.substr(i, j - i));
                }
            }
            // prepare for the next number
            if (equation[j] == '=') {
                sign = 1;  
                k = 1;
            } else {
                sign = (equation[j] == '+') ? 1 : -1;
            }
            i = j + 1;
        }
        // different cases
        int x = coef[0][0] - coef[1][0];
        int num = coef[1][1] - coef[0][1];
        if (x == 0) {
            return (num == 0) ? "Infinite solutions" : "No solution";
        } else {
            return "x=" + to_string(num / x);
        }
    }
};