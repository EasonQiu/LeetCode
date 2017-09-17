// You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
// One envelope can fit into another if and only if both the width and height of one envelope 
// is greater than the width and height of the other envelope.

// What is the maximum number of envelopes can you Russian doll? (put one inside other)

// Example:
// Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian 
// doll is 3 ([2,3] => [5,4] => [6,7]).


// Sort the array. Ascend on width and descend on height if width are same.
// Find the longest increasing subsequence based on height.
// Since the width is increasing, we only need to consider height.
// min_last[i] stores the min last element of subsequence of length i
class MyComparator {
	bool operator() (pair<int, int> &lhs, pair<int, int> &rhs) {
		return ((lhs.first < rhs.first) ||
						(lhs.first == rhs.first && lhs.second > rhs.second));
	}
};

class Solution {
public:
  int maxEnvelopes(vector<pair<int, int>>& envelopes) {
  	if (envelopes.size() <= 1)  return envelopes.size();
  	sort(envelopes.begin(), envelopes.end(), MyComparator);
  	vector<int> min_last;
  	for (auto &pair : envelopes) {
  		auto pos = lower_bound(min_last.begin(), min_last.end(), pair.second);
  		if (pos == min_last.end()) {
  			min_last.push_back(pair.second);
  		} else {
  			*pos = pair.second;
  		}
  	}
  	return min_last.size();
  }
};

// opt[i] denotes the max number of envelopes ending with the i-th elements
// O(n^2)
class Solution {
public:
  int maxEnvelopes(vector<pair<int, int>>& envelopes) {
  	if (envelopes.size() <= 1)  return envelopes.size();
  	sort(envelopes.begin(), envelopes.end());
  	vector<int> dp(envelopes.size(), 1);
  	int ans = 1;
  	for (int i = 0; i < envelopes.size(); ++i) {
  		for (int j = 0; j < i; ++j) {
  			if (envelopes[j].first < envelopes[i].first &&
  				  envelopes[j].second < envelopes[i].second) {
  				dp[i] = max(dp[i], dp[j] + 1);
  			}
  		}
  		ans = max(ans, dp[i]);
  	}
  	return ans;
  }
};