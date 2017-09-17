// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls on to the hole.

// Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving the shortest distance. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). Output the moving directions by using 'u', 'd', 'l' and 'r'. Since there could be several different shortest ways, you should output the lexicographically smallest way. If the ball cannot reach the hole, output "impossible".

// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The ball and the hole coordinates are represented by row and column indexes.

// Example 1

// Input 1: a maze represented by a 2D array

// 0 0 0 0 0
// 1 1 0 0 1
// 0 0 0 0 0
// 0 1 0 0 1
// 0 1 0 0 0

// Input 2: ball coordinate (rowBall, colBall) = (4, 3)
// Input 3: hole coordinate (rowHole, colHole) = (0, 1)

// Output: "lul"
// Explanation: There are two shortest ways for the ball to drop into the hole.
// The first way is left -> up -> left, represented by "lul".
// The second way is up -> left, represented by 'ul'.
// Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".

// Note:
// There is only one ball and one hole in the maze.
// Both the ball and hole exist on an empty space, and they will not be at the same position initially.
// The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// The maze contains at least 2 empty spaces, and the width and the height of the maze won't exceed 30.


class Solution {
private:
    struct Node {
        int x, y, l;
        string path;
        Node(int x_, int y_, int l_, string path_ = "") : x(x_), y(y_), l(l_), path(path_) {}
    };
    
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int row = maze.size(), col = maze[0].size();
        vector<vector<int> > length(row, vector<int>(col, INT_MAX));  // min_len from start
        char marks[4] = {'d', 'l', 'r', 'u'};
        int dir[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        string ans = "impossible";
        maze[hole[0]][hole[1]] = -9;  // mark hole in the maze
        queue<Node> nodes;
        nodes.push(Node(ball[0], ball[1], 0));
        while (!nodes.empty()) {
            // update the min_steps of the current position
            Node p = nodes.front();  nodes.pop();
            if (p.l > length[p.x][p.y])  continue;  // 不能用>=，因为同样len的path可能lexi小
            length[p.x][p.y] = p.l;
            // test 4 directions
            for (int k = 0; k < 4; ++k) {
                // move to the next position
                int i = p.x + dir[k][0], j = p.y + dir[k][1];
                int cur_len = p.l;
                while (i >= 0 && i < row && j >= 0 && j < col && maze[i][j] != -9 && maze[i][j] != 1) {
                    i += dir[k][0];  j += dir[k][1];
                    ++cur_len;
                }
                // base case
                if (i == hole[0] && j == hole[1]) {
                    string cur_path = p.path + marks[k];
                    if (cur_len < length[hole[0]][hole[1]] ||
                        (cur_len == length[hole[0]][hole[1]] && cur_path < ans)) {
                        length[hole[0]][hole[1]] = cur_len;
                        ans = cur_path;
                    }
                    continue;
                }
                // regular case
                i -= dir[k][0];  j -= dir[k][1];
                if (i == p.x && j == p.y)  continue;  // can't move
                if (cur_len > length[i][j])  continue;
                nodes.push(Node(i, j, cur_len, p.path + marks[k]));
            }
        }
        return ans;
    }
};