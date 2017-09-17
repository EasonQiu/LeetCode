// Given a non-empty array of integers, return the k most frequent elements.

// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { // queue
        vector<int> ans;
        // build hashmap to count the numbers
        unordered_map<int, int> counts;  // <number, count>
        for (int num : nums)  ++counts[num];
        // find the heap for frequency
        priority_queue<pair<int, int> > frequent;  // <count, number>
        for (auto& pair : counts)  frequent.push(make_pair(pair.second, pair.first));
        // get the top k elements
        while (--k >= 0) {
            ans.push_back(frequent.top().second);
            frequent.pop();
        }
        // final result
        return ans;
    }

	vector<int> topKFrequent1(vector<int>& nums, int k) { // tree
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
	for (int num : ans)  cout << num << " ";
	return 0;
}