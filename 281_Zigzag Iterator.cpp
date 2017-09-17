// Given two 1d vectors, implement an iterator to return their elements alternately.

// For example, given two 1d vectors:

// v1 = [1, 2]
// v2 = [3, 4, 5, 6]
// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

// Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vec1 = v1;  vec2 = v2;
        size = vector<int>{v1.size(), v2.size()};
        if (!v1.empty())  index.push(make_pair(0, 0));
        if (!v2.empty())  index.push(make_pair(1, 0));
    }

    int next() {
        int vi = index.front().first;
        int i  = index.front().second;
        index.pop();
        int val = (vi == 0) ? vec1[i] : vec2[i];
        if (i + 1 < size[vi])  index.push(make_pair(vi, i + 1));
        return val;
    }

    bool hasNext() {
        return !index.empty();
    }
    
private:
    vector<int> vec1, vec2;
    queue<pair<int, int> > index;
    vector<int> size;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */