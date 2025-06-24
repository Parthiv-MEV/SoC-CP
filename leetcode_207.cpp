class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& e : prerequisites) {
            graph[e[1]].push_back(e[0]);
            ++indegree[e[0]];
        }
        
        queue<int> q;
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto& next : graph[curr]) {
                --indegree[next];
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
            --numCourses;
        }
        
        return numCourses == 0;
    }
};
