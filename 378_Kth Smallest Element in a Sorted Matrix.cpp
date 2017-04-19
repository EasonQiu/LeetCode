#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
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
            // for (int i = 0; i < n; ++i) {
            //     int rowCount = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            //     count += rowCount;
            // }
            if (count < k)  left = mid + 1;
            else  right = mid;
        }
        return left;
    }
};

class Tuple {
public:
	int val, x, y;
	Tuple(int v1, int v2, int v3) : val(v1), x(v2), y(v3) {};
	friend bool compare(Tuple const& t1, Tuple const& t2);
};
// compare function for priority queue
bool compare(Tuple const& t1, Tuple const& t2) {
	return t1.val > t2.val;
}

class Solution1 {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        priority_queue<Tuple, vector<Tuple>, function<bool(Tuple, Tuple)> > pq(compare);
        for (int i = 0; i < row; ++i) {
        	pq.push(Tuple(matrix[i][0], i, 0));
        }
        Tuple t(0,0,0);
        for (int i  = 0; i < k; ++i) {
        	t.x = pq.top().x;  t.y = pq.top().y;  t.val = pq.top().val;
			pq.pop();
        	if (t.y + 1 < col)  pq.push(Tuple(matrix[t.x][t.y+1], t.x, t.y+1));
        }
        return t.val;
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