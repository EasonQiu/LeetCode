class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count; // <char, count>
        for (char ch : s)  ++count[ch];
        map<int, vector<char> > freq;   // <count, array of char>
        for (auto &pair : count)  freq[pair.second].push_back(pair.first);
        string ans = "";
        for (auto pair = freq.rbegin(); pair != freq.rend(); ++pair) {
            for (char ch : pair->second) {
                ans += string(pair->first, ch);
            }
        }
        return ans;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = {0};
        for (char ch : s)
            ++counts[ch];
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
        });
        return s;
    }
};