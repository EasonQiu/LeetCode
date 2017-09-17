// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
  int maxPoints(vector<Point>& points) {
  	if (points.empty())  return 0;
  	double max_slope = 2 * double(INT_MAX) + 2;
  	int max_num = 0, x1, y1, x2, y2;
  	for (int i = 0; i < points.size(); ++i) {
  		x1 = points[i].x;  y1 = points[i].y;
  		unordered_map<double, int> count;
  		int cur_max = 0, duplicate = 0;
  		for (int j = 0; j < points.size(); ++j) {
  			x2 = points[j].x;  y2 = points[j].y;
  			if (x2 == x1 && y2 == y1) { // duplicate points on (x1,y1)
  				++duplicate;
  			} else if (x2 == x1) { // vertical line case
  				cur_max = max(cur_max, ++count[max_slope]);
  			} else { // regular case
  				cur_max = max(cur_max, ++count[(y2 - y1) / double(x2 - x1)]);
  			}
  		}
  		max_num = max(max_num, cur_max + duplicate);
  	}
  	return max_num;
  }
};