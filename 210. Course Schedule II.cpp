class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    if (numCourses == 0)  return vector<int>();
    // init the in_degree & out_degree
    int in_degree[numCourses] = {};
    unordered_map<int, vector<int> > out_degree;
    for (auto& pair : prerequisites) {
      ++in_degree[pair.first];
      out_degree[pair.second].push_back(pair.first);
    }
    // init the zero_degrees
    queue<int> zero_degrees;
    for (int i = 0; i < numCourses; ++i) {
      if (in_degree[i] == 0)  zero_degrees.push(i);
    }
    // topologic sort
    vector<int> ans;
    int curr;
    while (!zero_degrees.empty()) {
      curr = zero_degrees.front();  zero_degrees.pop();
      ans.push_back(curr);
      for (int next : out_degree[curr]) {
        if (--in_degree[next] == 0)  zero_degrees.push(next); 
      }
    }
    return ans.size() == numCourses ? ans : vector<int>();
  }
};