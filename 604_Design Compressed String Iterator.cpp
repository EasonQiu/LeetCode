// Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

// The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

// next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
// hasNext() - Judge whether there is any letter needs to be uncompressed.

// Note:
// Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

// Example:

// StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

// iterator.next(); // return 'L'
// iterator.next(); // return 'e'
// iterator.next(); // return 'e'
// iterator.next(); // return 't'
// iterator.next(); // return 'C'
// iterator.next(); // return 'o'
// iterator.next(); // return 'd'
// iterator.hasNext(); // return true
// iterator.next(); // return 'e'
// iterator.hasNext(); // return false
// iterator.next(); // return ' '


class StringIterator {
public:
    StringIterator(string compressedString) {
        string& s = compressedString;
        if (s.empty())  return;
        int i = 0;
        while (i < s.size()) {
            int j = i + 1;
            while (j < s.size() && isdigit(s[j]))  ++j;
            que.push(make_pair(s[i], stoi(s.substr(i + 1, j - i - 1))));
            i = j;
        }
    }
    
    char next() {
        if (que.empty())  return ' ';
        char ch = que.front().first;
        if (--que.front().second == 0)  que.pop();
        return ch;
    }
    
    bool hasNext() {
        return !que.empty();
    }
    
private:
    queue<pair<char, int> > que;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */