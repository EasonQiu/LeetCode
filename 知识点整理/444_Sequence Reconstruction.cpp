// Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

// Example 1:

// Input:
// org: [1,2,3], seqs: [[1,2],[1,3]]

// Output:
// false

// Explanation:
// [1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.

// Input:
// org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]

// Output:
// true


// corner cases: [1], [[],[]]
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        int indegree[n + 1] = {0};
        unordered_map<int, unordered_set<int> > outdegree;
        unordered_set<int> nums;
        // init the relations in seqs
        for (vector<int>& seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] > n || seq[i] < 1)  return false;  // corner cases
                nums.insert(seq[i]);
                if (i == 0)  continue;
                auto is_exist = outdegree[seq[i - 1]].insert(seq[i]);
                if (is_exist.second)  ++indegree[seq[i]];
            }
        }
        if (nums.size() != n)  return false;
        // init the zero indegree
        queue<int> zero_indegree;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0)  zero_indegree.push(i);
        }
        // topological sort
        int size = 0;
        while (!zero_indegree.empty()) {
            if (zero_indegree.size() != 1)  return false;
            ++size;
            int curr = zero_indegree.front();  
            zero_indegree.pop();
            for (int next : outdegree[curr]) {
                if (--indegree[next] == 0)  zero_indegree.push(next);
            }
        }
        return size == n;
    }
};