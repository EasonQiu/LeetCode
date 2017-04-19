class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans(numCourses);
        // count the inDegree and outDegree of nodes
        vector<int> inDegree(numCourses);
        unordered_map<int, unordered_set<int> > outDegree(numCourses);
        for (auto edge : prerequisites) {
        	auto flag = outDegree[edge.second].insert(edge.first);
        	// solve the cases of duplicate edges
        	if (flag.second) ++inDegree[edge.first];
        }
        // create hashset that contains zero indegree nodes
        unordered_set<int> zeroInDegree(numCourses);
        for (int i = 0; i < numCourses; ++i) {
        	if (inDegree[i] == 0)  zeroInDegree.insert(i);
        }
        // topological sort
        int count = 0;
        while (zeroInDegree.size() != 0) {
        	// get one node from zeroInDegree hashset
        	int index = *zeroInDegree.begin();
        	zeroInDegree.erase(index);
        	ans[count++] = index;
        	// update the indegree and outdegree
        	for (int linked : outDegree[index]) {
        		if (--inDegree[linked] == 0)  zeroInDegree.insert(linked);
        	}
        }

        if (count == numCourses)  return ans;
        else return vector<int>();
    }
};