// Given a collection of distinct numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

// inline permutation
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
  	vector<vector<int> > results;
  	dfs(nums, 0, results);
  	return results;
  }

  void dfs(vector<int> &nums, int begin, vector<vector<int> > &results) {
  	if (begin == nums.size()) {
  		results.push_back(nums);
  		return;
  	}
  	for (int i = begin; i < nums.size(); ++i) {
  		swap(nums[begin], nums[i]);
  		dfs(nums, begin + 1, results);
  		swap(nums[begin], nums[i]);
  	}
  }
};


class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
  	if (nums.empty())  return results;
  	vector<int> answer(nums.size());
  	vector<bool> visited(nums.size());
  	dfs(nums, visited, answer, 0);
  	return results;
  }

  void dfs(vector<int> &nums, vector<bool> &visited, vector<int> &answer, int index) {
  	if (index == answer.size()) {
  		results.push_back(answer);
  		return;
  	}
  	for (int i = 0; i < nums.size(); ++i) {
  		if (visited[i])  continue;
  		answer[index] = nums[i];  visited[i] = true;
  		dfs(nums, visited, answer, index + 1);
  		visited[i] = false;
  	}
  }
 private:
 	vector<vector<int> > results;
};