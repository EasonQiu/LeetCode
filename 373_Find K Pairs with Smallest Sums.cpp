// You are given two integer arrays nums1 and nums2 sorted in ascending 
// order and an integer k.

// Define a pair (u,v) which consists of one element from the first array 
// and one element from the second array.

// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

// Example 1:
// Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
// Return: [1,2],[1,4],[1,6]
// The first 3 pairs are returned from the sequence:
// [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

class Pair {
 public:
 	int sum, ix1, ix2;
 	Pair() : sum(0), ix1(0), ix2(0) {}
 	Pair(int n, int ix1, int ix2) : sum(n), ix1(ix1), ix2(ix2) {}
};

class PairCompare {
 public:
 	bool operator() (const Pair &lhs, const Pair &rhs) const {
 		return lhs.sum > rhs.sum;
 	}
};

class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int> > ans;
		if (nums1.empty() || nums2.empty())  return ans;
		vector<vector<bool> > visited(nums1.size(), vector<bool>(nums2.size(), false));
		priority_queue<Pair, vector<Pair>, PairCompare> pq;
		Pair curr;
		// get pair from priority queue k times
		pq.emplace(nums1[0] + nums2[0], 0, 0);
		while (k-- > 0 && !pq.empty()) {
			// get one pair from the priority queue
			curr = pq.top();  pq.pop();
			ans.push_back(make_pair(nums1[curr.ix1], nums2[curr.ix2]));
			// push two bigger pair into the priority queue
			if (curr.ix1 + 1 < nums1.size() && !visited[curr.ix1 + 1][curr.ix2]) {
				pq.emplace(nums1[curr.ix1 + 1] + nums2[curr.ix2], curr.ix1 + 1, curr.ix2);
				visited[curr.ix1 + 1][curr.ix2] = true;
			}
			if (curr.ix2 + 1 < nums2.size() && !visited[curr.ix1][curr.ix2 + 1]) {
				pq.emplace(nums1[curr.ix1] + nums2[curr.ix2 + 1], curr.ix1, curr.ix2 + 1);
				visited[curr.ix1][curr.ix2 + 1] = true;
			}
		}
		// final result
		return ans;
	}
};

int main() {
	vector<int> nums1 = {1, 1, 2}, nums2 = {1, 2, 3};
	Solution sol;
	vector<pair<int, int> > ans = sol.kSmallestPairs(nums1, nums2, 10);

	for (auto pair : ans) {
		cout << pair.first << " " << pair.second << " " << pair.first + pair.second << endl;
	}

	return 0;
}