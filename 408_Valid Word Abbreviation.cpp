// Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

// A string such as "word" contains only the following valid abbreviations:

// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
// Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

// Note:
// Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

// Example 1:
// Given s = "internationalization", abbr = "i12iz4n":

// Return true.
// Example 2:
// Given s = "apple", abbr = "a2e":

// Return false.

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int size1 = word.size(), size2 = abbr.size();
        int i = 0, j = 0;
        while (i < size1 && j < size2) {
            if (!isdigit(abbr[j])) {
                if (abbr[j++] != word[i++])  return false;
            } else {
                if (abbr[j] == '0')  return false; // corner case "01"
                int count = 0;
                while (j < size2 && isdigit(abbr[j])) {
                    count = count * 10 + abbr[j++] - '0';
                }
                if (i + count > size1)  return false;
                i += count;
            }
        }
        return (i == size1 && j == size2);
    }
};