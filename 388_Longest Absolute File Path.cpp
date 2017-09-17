// Suppose we abstract our file system by a string in the following manner:

// The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

// dir
//     subdir1
//     subdir2
//         file.ext
// The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

// The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

// dir
//     subdir1
//         file1.ext
//         subsubdir1
//     subdir2
//         subsubdir2
//             file2.ext
// The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

// We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

// Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

// 以\n为分割
class Solution {
public:
    int lengthLongestPath(string input) {
        int max_len = INT_MIN;
        int left = 0, right;
        vector<int> folder; // len of different level folders
        while (left < input.size()) {
            // find the next first '\n'
            bool is_file = false;
            right = left;
            while (right < input.size() && input[right] != '\n') {
                if (input[right++] == '.')  is_file = true;
            }
            // count the number of '\t'
            int count = 0;
            for (int i = left; i < right; ++i) {
                if (input[left + count] != '\t')  break;
                ++count;
            }
            int name_len = right - left - count;
            // check if it's a file
            if (is_file) {
                max_len = max(max_len, accumulate(folder.begin(), folder.begin() + count, count + name_len));
            } else {
                folder.resize(count + 1);
                folder[count] = name_len;
            }
            // update left
            left = right + 1;
        }
        return max(max_len, 0);
    }
};

class Solution {
public:
    int lengthLongestPath(string input) {
        int size = input.size();
        int max_len = INT_MIN;
        int left = -1, right;
        vector<int> folders; // length of each folder, plus '/'
        while (left < size) {
            // split the input
            right = input.find('\n', left + 1);
            if (right == input.npos)  right = input.size();
            string split = input.substr(left + 1, right - left - 1);
            left = right;
            // count the level of path
            int level = 0;
            while (level < split.size() && split[level] == '\t')  ++level;
            int len = split.size() - level;
            // check if it's a file
            if (split.find('.', level) != split.npos) { // file
                max_len = max(max_len, accumulate(folders.begin(), folders.begin() + level, len));
            } else { // folder
                folders.resize(level + 1);
                folders[level] = len + 1;
            }
        }
        return max(max_len, 0);
    }
};