#include <iostream>
#include <priority_queue>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) { // tree
        vector<int> answer;
        // build map to count frequency
        unordered_map<int, int> numCount; // <num, frequency>
        for (int& val : nums)  ++numCount[val];
        // build map
        map<int, vector<int> > map; // <frequency, numbers>
    	for (auto& pair : numCount)  map[pair.second].push_back(pair.first);
    	// get top k
    	for (auto itr = map.rbegin(); itr != map.rend(); ++itr) {
    		for (int& val : itr->second) {
    			answer.push_back(val);  --k;
    			if (k == 0)  return answer;
    		}
    	}
    	return answer;
    }

    vector<int> topKFrequent2(vector<int>& nums, int k) { // bucket sort, 13%
        vector<int> answer;
        // build map to count frequency
        unordered_map<int, int> numCount; // <num, frequency>
        for (int val : nums)  ++numCount[val];
        // use bucket sort
        vector<vector<int> > bucket(nums.size()+1, vector<int>());
    	for (auto pair : numCount) {
    		bucket[pair.second].push_back(pair.first);
    	}
    	// get the top k frequency
    	for (int i = bucket.size()-1; i >= 0; --i) {
    		if (bucket[i].size() > 0) {
    			for (int val : bucket[i]) {
    				answer.push_back(val);  --k;
    				if (k == 0) return answer;
    			}
    		}
    	}
    	return answer;
    }
};

int main() {
	int arr[] = {1,1,1,2,2,3};
	vector<int> nums(arr, arr+6);
	Solution s;
	vector<int> ans = s.topKFrequent(nums, 2);
	for (int num : nums)  cout << num << " ";
	return 0;
}