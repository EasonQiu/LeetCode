// For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

// Example 1:

// Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

//         0
//         |
//         1
//        / \
//       2   3
// return [1]

// Example 2:

// Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5
// return [3, 4]

// Note:

// (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

// (2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


// topological sort, 从leaves开始BFS
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1)  return vector<int>{0};  // corner cases
        int count[n] = {};
        unordered_map<int, vector<int> > connects; // node, its connections
        for (auto& pair : edges) {
            connects[pair.first].push_back(pair.second);
            connects[pair.second].push_back(pair.first);
            ++count[pair.first];  ++count[pair.second];
        }
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (count[i] == 1)  leaves.push(i);
        }
        int left_num = n;
        while (!leaves.empty()) {
            if (leaves.size() == left_num)  break;  // root level
            int size = leaves.size();
            for (int i = 0; i < size; ++i) {
                int curr = leaves.front();  leaves.pop();
                for (int next : connects[curr]) {
                    if (--count[next] == 1)  leaves.push(next);
                }
            }
            left_num -= size;
        }
        vector<int> ans;
        while (!leaves.empty()) {
            ans.push_back(leaves.front());  leaves.pop();
        }
        return ans;
    }
};