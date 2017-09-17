// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

// Example:
// (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
// (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
// Note:
// You may assume all input has valid answer.

// Follow Up:
// Can you do it in O(n) time and/or in-place with O(1) extra space?



// Roughly speaking I put the smaller half of the numbers on the even indexes and 
// the larger half on the odd indexes.

// I put the smaller half of the numbers on the even indexes and the larger half on the odd 
// indexes, both from right to left:

// Small half:  M . M . S . S      Small half:  M . S . S . S .
// Large half:  . L . L . M .      Large half:  . L . M . M . M
// --------------------------      --------------------------
// Together:    M L M L S M S      Together:    M L S M S M S M
class Solution {
public:
  void wiggleSort(vector<int>& nums) {
  	int size = nums.size();
  	// find the middle number
  	auto midptr = nums.begin() + n / 2;
  	nth_element(nums.begin(), midptr, nums.end());
  	int mid_num = *midptr;

  	// nums:    0, 1, 2, 3, 4
  	// virtual: 1, 3, 0, 2, 4 (values should large to small)   <- i to iterate
  	// value:   4, 7, 5, 5, 1
  	#define virtual(i) nums[(2 * i + 1) % (size | 1)]

  	// left point to the next pos of larger than mid_num ones
  	// right point to the next pos of smaller than mid_num ones
  	int left = 0, i = 0, right = size - 1;
  	while (i <= right) {
  		if (virtual(i) > mid_num) {
  			// 因为left是已经判断过大小一定>=mid_num，所以可以用i++直接判断下一个值
  			swap(virtual(i++), virtual(left++)); 
  		} else if (virtual(i) < mid_num) {
  			swap(virtual(i), virtual(right--));
  		} else {
  			i++;
  		}
  	}
  }
};


class Solution {
public:
  void wiggleSort(vector<int>& nums) {
  	int size = nums.size();
  	vector<int> copy(nums);
  	sort(copy.begin(), copy.end());
  	int smaller = (size - 1) / 2, larger = size - 1;
  	for (int i = 0; i < size; i += 2) {
  		nums[i] = copy[smaller--];
  	}
  	for (int i = 1; i < size; i += 2) {
  		nums[i] = copy[larger--];
  	}
  }
};