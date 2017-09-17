// Follow up for H-Index: What if the citations array is sorted in ascending order? 
// Could you optimize your algorithm?

// find max num of H-index
class Solution {
public:
  int hIndex(vector<int>& citations) {
  	if (citations.empty())  return 0;
  	int size = citations.size();
  	int left = 0, right = size - 1, mid;
  	while (left + 1 < right) {
  		int mid = left + (right - left) / 2;
  		if (citations[mid] >= size - mid) {
  			right = mid;
  		} else {
  			left = mid + 1;
  		}
  	}
  	if (citations[left] >= size - left) {
  		return size - left;
  	} else if (citations[right] >= size - right) {
  		return size - right;
  	}
  	return 0;
  }
};