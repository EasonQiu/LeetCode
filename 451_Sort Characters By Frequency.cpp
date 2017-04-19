class Solution {
public:
    string frequencySort(string s) { // beats 66.70%
        unordered_map<char, int> charCount;
        for (char c : s)  ++charCount[c];
        // build BST map
        map<int, vector<char> > map;
    	for (auto& pair : charCount)  map[pair.second].push_back(pair.first);
    	// create string
    	string answer = "";
    	for (auto itr = map.rbegin(); itr != map.rend(); ++itr) {
    		for (char c : itr->second) {
    			string s(itr->first, c);  answer += s;
    		}
    	}
    	return answer;
    }
};