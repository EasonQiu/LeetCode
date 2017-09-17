// There are a total of n courses you have to take, labeled from 0 to n - 1.
// Some courses may have prerequisites, for example to take course 0 you have to first 
// take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, output ALL the 
// possible solutions for you to finish all courses?

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
#include <deque>
using namespace std;

class Solution {
 public:
  vector<vector<int> > findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int> > all_orders;
    vector<int> order;
    // init indegree and outdegree hashmap
    in_degree.resize(numCourses);  out_degree.clear();
    for (pair<int, int>& pair : prerequisites) {
      ++in_degree[pair.first];
      out_degree[pair.second].push_back(pair.first);
    }
    // init the hashset that contains courses without prerequisites
    for (int i = 0; i < numCourses; ++i) {
      if (in_degree[i] == 0)  zero_in_degrees.push_back(i);
    }
    // take the course from zero_in_degrees recursively
    topoSort(prerequisites, numCourses, order, all_orders);
    // final result
    return all_orders;
  }

  void topoSort(const vector<pair<int, int> > &prerequisites, int numCourses,
                vector<int> &order, vector<vector<int> > &all_orders) {
    if (zero_in_degrees.empty()) {
      if (numCourses == 0)  all_orders.push_back(order);
      return;
    }
    int size = zero_in_degrees.size(), curr_course;
    for (int i = 0; i < size; ++i) {
      // get one course from queue
      curr_course = zero_in_degrees.front();  zero_in_degrees.pop_front();
      order.push_back(curr_course);
      for (int next_course : out_degree[curr_course]) {
        if (--in_degree[next_course] == 0) {
          zero_in_degrees.push_back(next_course);
        }
      }
      // next level recursion
      topoSort(prerequisites, numCourses - 1, order, all_orders);
      // roll back operations
      for (int next_course : out_degree[curr_course]) {
        if (in_degree[next_course]++ == 0) {
          zero_in_degrees.pop_back();
        }
      }
      order.pop_back();
      zero_in_degrees.push_back(curr_course);
    }
  }

 private:
  vector<int> in_degree;  // number of prerequisite courses
  unordered_map<int, vector<int> > out_degree;  // <prerequisite course, pairs>
  deque<int> zero_in_degrees;
};

int main() {
  vector<pair<int, int> > prerequisites;
  prerequisites.push_back(make_pair(1,0));
  prerequisites.push_back(make_pair(3,1));
  prerequisites.push_back(make_pair(3,2));

  Solution s;
  vector<vector<int> > all_orders = s.findOrder(4, prerequisites);
  for (vector<int>& order : all_orders) {
    for (int course : order)  cout << course << " ";
    cout << endl;
  }

  return 0;
}