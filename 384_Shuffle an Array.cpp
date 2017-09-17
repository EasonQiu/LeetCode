// Shuffle a set of numbers without duplicates.

// Example:

// // Init an array with set 1, 2, and 3.
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);

// // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
// solution.shuffle();

// // Resets the array back to its original configuration [1,2,3].
// solution.reset();

// // Returns the random shuffling of array [1,2,3].
// solution.shuffle();


class Solution {
 public:
  Solution(vector<int> nums) {
  	nums_ = nums;
  }
    
  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
  	return nums_;
  }
    
  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
  	vector<int> copy(nums_);
  	for (int i = 0; i < copy.size(); ++i) {
  	    int j = rand() % (i + 1);
  		swap(copy[i], copy[j]);
  	}
  	return copy;
  }

 private:
 	vector<int> nums_;
};