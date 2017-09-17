// You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

// Example 1:
// Input: [1,2,3,3,4,5]
// Output: True
// Explanation:
// You can split them into two consecutive subsequences : 
// 1, 2, 3
// 3, 4, 5
// Example 2:
// Input: [1,2,3,3,4,4,5,5]
// Output: True
// Explanation:
// You can split them into two consecutive subsequences : 
// 1, 2, 3, 4, 5
// 3, 4, 5
// Example 3:
// Input: [1,2,3,4,4,5]
// Output: False
// Note:
// The length of the input is in range of [1, 10000]

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count, tail; // <num, count>,  <next num of last element in sequence, count>
        for (int& num : nums)  ++count[num];
        for (int& num : nums) {
            if (count[num] == 0)  continue;  // this num is already used
            if (tail[num] > 0) {  //if the ele can be added in the last consecutive sequence
                --count[num];
                --tail[num];  ++tail[num + 1];
            } else if (count[num + 1] > 0 && count[num + 2] > 0) {  //this ele should form a consecutive sequence by itself
                --count[num];  --count[num + 1];  --count[num + 2];
                ++tail[num + 3];
            } else {  //doesn't belong to any consecutive sequence
                return false;
            }
        }
        return true;
    }
};