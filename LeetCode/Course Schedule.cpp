class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses);
        for (auto i:prerequisites) {
            indegree[i[0]]++;
            graph[i[1]].push_back(i[0]);
        }
        queue<int> q;
        for (int i=0;i<numCourses;i++) {
            if (!indegree[i])
                q.push(i);
        }
        if (q.empty())
            return false;
        while (!q.empty()) {
            auto t=q.front();
            q.pop();
            for (auto i:graph[t]) {
                indegree[i]--;
                if (!indegree[i])
                    q.push(i);
            }
        }
        for (int i=0;i<numCourses;i++)
            if (indegree[i]>0)
                return false;
        return true;
    }
};