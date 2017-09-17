// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

// Find all strobogrammatic numbers that are of length = n.

// For example,
// Given n = 2, return ["11","69","88","96"].


class Solution {  // beats 99.65%
public:
    vector<string> findStrobogrammatic(int n) {
        if (n <= 0)  return vector<string>();
        vector<string> ans;
        string num(n, ' ');
        helper(0, n - 1, num, ans);
        return ans;
    }
    
    void helper(int l, int r, string &num, vector<string> &ans) {
        if (l > r) {
            ans.push_back(num);
        } else if (l == r) {
            for (int i = 0; i < 3; ++i) {
                num[l] = pairs[i][0];
                helper(l + 1, r, num, ans);
            }
        } else {
            int i = (l == 0) ? 1 : 0;
            for (; i < 5; ++i) {
                num[l] = pairs[i][0];  num[r] = pairs[i][1];
                helper(l + 1, r - 1, num, ans);
            }
        }
    }
    
private:
    string pairs[5] = {"00", "11", "88", "69", "96"};
};