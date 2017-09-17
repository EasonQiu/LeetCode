// 用DFS时间复杂度太高，因为当不同path中间走到同一个格子后，之后的搜索完全一致。
class Solution {
private:
    struct Node {
        int x, y, len;
        Node(int x_, int y_, int len_) : x(x_), y(y_), len(len_) {}
    };
    
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size();
        vector<vector<int> > length(row, vector<int>(col, INT_MAX));  // min_steps from start point
        int dir[5] = {0, 1, 0, -1, 0};
        queue<Node> nodes;
        nodes.push(Node(start[0], start[1], 0));
        while (!nodes.empty()) {
            Node p = nodes.front();  nodes.pop();
            // set the min_steps of the current node
            if (p.len >= length[p.x][p.y])  continue;
            length[p.x][p.y] = p.len;
            if (p.x == destination[0] && p.y == destination[1])  continue;
            // move in 4 directions
            for (int k = 0; k < 4; ++k) {
                int i = p.x + dir[k], j = p.y + dir[k + 1];
                int cur_len = 0;
                while (i >= 0 && i < row && j >= 0 && j < col && maze[i][j] == 0) {
                    i += dir[k];  j += dir[k + 1];
                    ++cur_len;
                }
                i -= dir[k];  j -= dir[k + 1];
                if (p.len + cur_len < length[i][j]) {
                    nodes.push(Node(i, j, p.len + cur_len));
                }
            }
        }
        if (length[destination[0]][destination[1]] == INT_MAX)  return -1;
        return length[destination[0]][destination[1]];
    }
};