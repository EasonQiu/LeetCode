// There are a total of n courses you have to take, labeled from 0 to n - 1.
// Some courses may have prerequisites, for example to take course 0 you have to first 
// take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, is it possible 
// for you to finish all courses?

// For example:
// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. 
// So it is possible.
// 2, [[1,0],[0,1]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0, 
// and to take course 0 you should also have finished course 1. So it is impossible.

// 感想：要用vector而不是hashmap来统计indegree的数量，因为有孤立节点的存在无法遍历到。
// 面试时候要问是否会有duplicate edges的存在。如果有那么out_degree要用hashset来去重。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    // init indegree and outdegree hashmap
    vector<int> in_degreee(numCourses);  // number of prerequisite courses
    unordered_map<int, vector<int> > out_degree;  // <prerequisite course, pairs>
    for (pair<int, int>& pair : prerequisites) {
      ++in_degreee[pair.first];
      out_degree[pair.second].push_back(pair.first);
    }
    // init the hashset that contains courses without prerequisites
    queue<int> zero_in_degrees;
    for (int i = 0; i < numCourses; ++i) {
      if (in_degreee[i] == 0)  zero_in_degrees.push(i);
    }
    // take the course from zero_in_degrees
    int curr_course;
    while (!zero_in_degrees.empty()) {
      --numCourses;
      curr_course = zero_in_degrees.front();  zero_in_degrees.pop();
      for (int next_course : out_degree[curr_course]) {
        if (--in_degreee[next_course] == 0) {
          zero_in_degrees.push(next_course);
        }
      }
    }
    // final result
    return numCourses == 0;
  }
};

int main() {
  vector<pair<int, int> > prerequisites;
  prerequisites.push_back(make_pair(1,0));
  // prerequisites.push_back(make_pair(0,1));

  Solution s;
  cout << s.canFinish(2, prerequisites) << endl;
  return 0;
}