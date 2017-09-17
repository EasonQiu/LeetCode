// 注意先判断在不在set2中再判断在不在dict中
class Solution {  // two way BFS
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(end))  return -1;
        unordered_set<string> set1 = {start};
        unordered_set<string> set2 = {end};
        string ATGC = "ATGC";
        int count = 0;
        while (!set1.empty() && !set2.empty()) {
            ++count;
            if (set1.size() > set2.size())  swap(set1, set2);
            unordered_set<string> next_level;
            for (string gene : set1) {
                for (int i = 0; i < gene.size(); ++i) {
                    char original = gene[i];
                    for (int k = 0; k < 4; ++k) {
                        if (ATGC[k] == original)  continue;
                        gene[i] = ATGC[k];
                        if (set2.count(gene))  return count;
                        if (!dict.count(gene))  continue;
                        next_level.insert(gene);
                        dict.erase(gene);
                    }
                    gene[i] = original;
                }
            }
            swap(set1, next_level);
        }
        return -1;
    }
};