// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

// Example 1:
//      0          3
//      |          |
//      1 --- 2    4
// Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

// Example 2:
//      0           4
//      |           |
//      1 --- 2 --- 3
// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

// Note:
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.


class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        parent = vector<int>(n);
        for (int i = 0; i < n; ++i)  parent[i] = i;
        int count = n;
        for (pair<int, int>& edge : edges) {
            if (finds(edge.first) != finds(edge.second)) {
                unions(edge.first, edge.second);
                --count;
            }
        }
        return count;
    }
    
    int finds(int i) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
    
    void unions(int i, int j) {
        parent[finds(i)] = finds(j);
    }
    
private:
    vector<int> parent;
};