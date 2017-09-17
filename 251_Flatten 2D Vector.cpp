// Implement an iterator to flatten a 2d vector.

// For example,
// Given 2d vector =

// [
//   [1,2],
//   [3],
//   [4,5,6]
// ]
// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

// Follow up:
// As an added challenge, try to code it using only iterators in C++ or iterators in Java.


// corner cases: [[],[3]], [[]]
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        if (vec2d.empty())  return;
        size = vec2d.size();
        iters = vector<vector<int>::iterator >(vec2d.size());
        ends =  vector<vector<int>::iterator >(vec2d.size());
        for (int i = 0; i < vec2d.size(); ++i) {
            iters[i] = vec2d[i].begin();
            ends[i]  = vec2d[i].end();
        }
    }

    // next 在进入函数之前已经指向下一个要输出的值
    int next() {
        return *(iters[i]++);
    }

    bool hasNext() {
        if (ends.empty())  return false;
        while (i < size && iters[i] == ends[i])  ++i;
        return i != size;
    }
    
private:
    int i = 0, size = 0;
    vector<vector<int>::iterator > iters, ends;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */