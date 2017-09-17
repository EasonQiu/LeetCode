// Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list 
// of favorite restaurants represented by strings.

// You need to help them find out their common interest with the least list index sum. 
// If there is a choice tie between answers, output all of them with no order requirement. 
// You could assume there always exists an answer.

// Example 1:
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
// Output: ["Shogun"]
// Explanation: The only restaurant they both like is "Shogun".

// Example 2:
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["KFC", "Shogun", "Burger King"]
// Output: ["Shogun"]
// Explanation: The restaurant they both like and have the least index sum is "Shogun" 
// with index sum 1 (0+1).


class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
  	// init the hashmap of list1
  	unordered_map<string, int> dict;
  	for (int i = 0; i < list1.size(); ++i) {
  		dict[list1[i]] = i;
  	}
  	// search in list2
  	vector<string> ans;
  	int min_sum = INT_MAX;
  	for (int i = 0; i < list2.size(); ++i) {
  		auto pos = dict.find(list2[i]);
  		if (pos != dict.end()) {
  			if (i + pos->second < min_sum) {
  				ans.clear();  ans.push_back(list2[i]);
  				min_sum = i + pos->second;
  			} else if (i + pos->second == min_sum) {
  				ans.push_back(list2[i]);
  			}
  		}
  	}
  	// final result
  	return ans;
  }
};