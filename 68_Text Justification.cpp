// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left justified and no extra space is inserted between words.

// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.

// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.

// 小心add多余空格的处理
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int left = 0;
        while (left < words.size()) {
            string line = words[left];
            int width = words[left].size();
            // find the rightmost index
            int right = left;
            while (right + 1 < words.size() && width + words[right + 1].size() + 1 <= maxWidth) {
                width += words[++right].size() + 1;
            }
            // calculate the spaces
            if (right == left) { // only one word in a line
                ans.push_back(line + string(maxWidth - width, ' '));
                left = right + 1;
                continue;
            } else if (right + 1 == words.size()) { // lase line
                for (int i = left + 1; i <= right; ++i)  line += " " + words[i];
                ans.push_back(line + string(maxWidth - width, ' '));
                break;
            }
            int avg = (maxWidth - width) / (right - left);
            int add = (maxWidth - width) % (right - left);
            for (int i = left + 1; i <= right; ++i) {
                line += string(1 + avg + ((i - left) <= add ? 1 : 0), ' ') + words[i];
            }
            ans.push_back(line);
            left = right + 1;
        }
        return ans;
    }
};