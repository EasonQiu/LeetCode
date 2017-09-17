// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

// For example:

// Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

// Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

// A tree is a connected acyclic graph.
// There is a unique path between every pair of vertices in G.
// G is connected, and it has (n - 1) edges.
// G is acyclic, and it has (n - 1) edges.


// A tree is a connected acyclic graph.
// There is a unique path between every pair of vertices in G.
// G is connected, and it has (n - 1) edges.
// G is acyclic, and it has (n - 1) edges.

// union find
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1)  return false;
        // init the parent array, set itself as parent
        parent = vector<int>(n);
        for (int i = 0; i < n; ++i)  parent[i] = i;
        // union sets
        int count = n;
        for (auto &pair : edges) {
            int p1 = finds(pair.first);
            int p2 = finds(pair.second);
            if (p1 != p2) {
                parent[p1] = p2; // unions(p1, p2);
                --count;
            }
        }
        return count == 1;
    }
    
    int finds(int i) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    // void unions(int i, int j) { // can omit
    //     parent[finds(i)] = finds(j);
    // }
    
private:
    vector<int> parent;
};


// dfs搜索的时候，时刻关注是否会导致往回走，走过的地方要标记
// corner case: 1 []
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1)  return false;
        if (n == 1)  return true;
        vector<vector<int> > graph(n, vector<int>());
        for (auto &pair : edges) {
            graph[pair.first].push_back(pair.second);
            graph[pair.second].push_back(pair.first);
        }
        if (graph.size() != n)  return false;
        // check if any two nodes are connected
        for (int i = 1; i < n; ++i) {
            vector<bool> visited(n);
            if (!isConnected(graph, visited, 0, i))  return false;
        }
        return true;
    }
    
    bool isConnected(vector<vector<int> > &graph, vector<bool> &visited, int curr, int target) {
        if (curr == target)  return true;
        if (visited[curr])  return false;
        visited[curr] = true;
        for (int next : graph[curr]) {
            if (isConnected(graph, visited, next, target))  return true;
        }
        return false;
    }
};