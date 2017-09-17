// Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

// Here is an example of version numbers ordering:

// 0.1 < 1.1 < 1.2 < 13.37

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = 0, l2 = 0, r1, r2;
        while (l1 < version1.size() || l2 < version2.size()) {
            // parse the current value
            int val1, val2;
            if (l1 < version1.size()) {
                r1 = version1.find('.', l1);
                if (r1 == -1)  r1 = version1.size();
                val1 = stoi(version1.substr(l1, r1 - l1));
                l1 = r1 + 1;
            } else {
                val1 = 0;
            }
            if (l2 < version2.size()) {
                r2 = version2.find('.', l2);
                if (r2 == -1)  r2 = version2.size();
                val2 = stoi(version2.substr(l2, r2 - l2));
                l2 = r2 + 1;
            } else {
                val2 = 0;
            }
            // compare two values
            if (val1 < val2)  return -1;
            if (val1 > val2)  return 1;
        }
        return 0;
    }
};