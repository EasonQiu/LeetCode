#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// hash talbe能reserve空间一定要提前预留，不然重新rehash非常费时！
// hash table用double作key，比用long作key计算hash function时费时！

class Solution { // beats 66.31%
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
    	if (points.size() <= 2)  return 0;
    	int count = 0;
    	for (int i = 0; i < points.size(); ++i) {
    		int x1 = points[i].first,  y1 = points[i].second;
    		// map<distance, num of points having the same distance
    		unordered_map<long, int> sameDis(points.size());
    		// create the map of this points[i]
    		for (int j = 0; j < points.size(); ++j) {
    			if (j == i)  continue;
    			int x2 = points[j].first,  y2 = points[j].second;
    			long dis = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    			++sameDis[dis];
    			// add the difference of combinations, A(n,2)-A(n-1,2)
    			if (sameDis[dis] >= 2)  count += 2 * sameDis[dis] - 2;
    		}
    	}
        return count;
    }
};

int main() {
	vector<pair<int, int> > points;
	points.push_back(make_pair(0,0));  points.push_back(make_pair(1,0));
	points.push_back(make_pair(-1,0)); points.push_back(make_pair(0,1));
	points.push_back(make_pair(0,-1));

	Solution s;
	cout << s.numberOfBoomerangs(points) << endl;
	return 0;
}