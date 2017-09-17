// Given a n x n matrix where each of the rows and columns are sorted 
// in ascending order, find the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not 
// the kth distinct element.

// Example:
// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,
// return 13.

// 解法：和merge k sorted lists一样
// 感想：自定义class时如果只定义了三个参数的，在之后的程序中不能用默认构造函数
//      灵活运用emplace的用法，简洁高效

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];
    while (left < right) {
      int mid = left + (right - left) / 2;
      // count the numbers that is smaller than mid
      int count = 0;
      int i = n - 1;
      int j = 0;
      while (i >= 0 && j < n) {
        if (matrix[i][j] <= mid) {
          count += i + 1;
          ++j;
        } else {
          --i;
        }
      }
      // check the count
      if (count < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};


class Node {
 public:
  int x_, y_, val_;
  Node(int x, int y, int val) : x_(x), y_(y), val_(val) {}
};

class NodeCompare {
 public:
  bool operator() (const Node &lhs, const Node &rhs) const {
    return lhs.val_ >= rhs.val_;
  }
};

class Solution { // merge k sorted list
public:
  int kthSmallest(vector<vector<int> >& matrix, int k) {
    int row = matrix.size(), col = matrix[0].size();
    priority_queue<Node, vector<Node>, NodeCompare> min_queue;
    // push the first element of each row
    for (int i = 0; i < row; ++i) {
      min_queue.emplace(i, 0, matrix[i][0]);
    }
    // pop k times from queue
    Node cur(0, 0, 0);
    while (k-- > 0) {
      cur = min_queue.top();  min_queue.pop();
      if (++cur.y_ < col) {
        min_queue.emplace(cur.x_, cur.y_, matrix[cur.x_][cur.y_]);
      }
    }
    // final result
    return cur.val_;
  }
};

class Solution2 {  // binary search
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1], mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            // count the number that is less than mid
            int count = 0, i = n - 1, j = 0; 
            while (i >= 0 && j < n) {
                if (matrix[i][j] <= mid) {
                    ++j;  count += i + 1;
                } else {
                    --i;
                }
            }
            if (count < k)  left = mid + 1;
            else  right = mid;
        }
        return left;
    }
};

int main() {
  vector<vector<int> > matrix(3, vector<int>(3));
  matrix[0][0] = 1;   matrix[0][1] = 5;   matrix[0][2] = 9;
  matrix[1][0] = 10;  matrix[1][1] = 11;  matrix[1][2] = 13;
  matrix[2][0] = 12;  matrix[2][1] = 13;  matrix[2][2] = 15;

  Solution s;
  cout << s.kthSmallest(matrix, 8) << endl;
  return 0;
}