// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


// OJ's undirected graph serialization:
// Nodes are labeled uniquely.

// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.

// The graph has a total of three nodes, and therefore contains three parts as separated by #.

// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
// Visually, the graph looks like the following:

//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// 同一个node参数传进去，必须return同一个copy后的对应node
class Solution { // DFS
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)  return NULL;
        if (map.find(node) != map.end())  return map[node];
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        map[node] = copy;
        for (UndirectedGraphNode* child : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(child));
        }
        return copy;
    }
    
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map; // <old ptr, clone ptr>
};


class Solution { // BFS
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)  return NULL;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        map[node] = copy;
        queue<UndirectedGraphNode*> queue;
        queue.push(node);
        while (!queue.empty()) {
            // nodes in the queue are copied already, but didn't link with its children
            UndirectedGraphNode* curr = queue.front();
            copy = map[curr];
            queue.pop();
            for (UndirectedGraphNode* child : curr->neighbors) {
                if (map.find(child) == map.end()) {
                    UndirectedGraphNode* child_copy = new UndirectedGraphNode(child->label);
                    map[child] = child_copy;
                    queue.push(child);  // BFS not visited yet!
                }
                copy->neighbors.push_back(map[child]);
            }
        }
        return map[node];
    }
    
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map; // <old ptr, clone ptr>
};