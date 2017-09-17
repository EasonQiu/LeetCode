// Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

// Example 1:
// Input: 12
// Output: 21
// Example 2:
// Input: 21
// Output: -1


// 2 4 3 5 5 4 2
//     j     i
class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int size = num.size();
        int j = size - 2;
        while (j >= 0 && num[j] >= num[j + 1])  --j;
        if (j == -1)  return -1;  // decreasing order
        int i = size - 1;
        while (num[i] <= num[j])  --i;
        swap(num[j], num[i]);
        reverse(num.begin() + j + 1, num.end());
        return (stol(num) > INT_MAX) ? -1 : stoi(num);
    }
};