// Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

// Example 1:
// Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
// Return 16
// The two words can be "abcw", "xtfn".

// Example 2:
// Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
// Return 4
// The two words can be "ab", "cd".

// Example 3:
// Given ["a", "aa", "aaa", "aaaa"]
// Return 0
// No such pair of words.


class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.empty())  return 0;
        int size = words.size();
        vector<int> hash(size);
        for (int i = 0; i < words.size(); ++i) {
            for (char ch : words[i]) {
                hash[i] |= 1 << (ch - 'a');
            }
        }
        size_t max_val = 0;
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (hash[i] & hash[j])  continue;
                max_val = max(max_val, words[i].size() * words[j].size());
            }
        }
        return max_val;
    }
};