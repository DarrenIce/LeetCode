class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses);
        vector<int> path;
        for (auto i:prerequisites) {
            indegree[i[0]]++;
            graph[i[1]].push_back(i[0]);
        }
        queue<int> q;
        for (int i=0;i<numCourses;i++) {
            if (!indegree[i])
                q.push(i);
        }
        while (!q.empty()) {
            auto t=q.front();
            q.pop();
            path.push_back(t);
            for (auto i:graph[t]) {
                if (--indegree[i]==0)
                    q.push(i);
            }
        }
        if (path.size()!=numCourses)
            return vector<int> {};
        return path;
    }
};